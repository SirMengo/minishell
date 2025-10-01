/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:11:56 by xalves            #+#    #+#             */
/*   Updated: 2025/10/01 11:37:55 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

static void	ft_allocate(char **tab, char const *s, char sep)
{
	int		i;
	int		start;
	int		len;
	char	quote_flag;

	i = 0;
	start = 0;
	quote_flag = 0;
	while (s[start])
	{
		while (s[start] == sep)
			start++;
		if (!s[start])
			break ;
		if ((s[start] == '<' || s[start] == '>') && s[start + 1] == s[start]
			&& quote_flag == 0) // handle double
		{
			tab[i++] = ft_substr(s, start, 2);
			start += 2;
		}
		else if ((s[start] == '<' || s[start] == '>' || s[start] == '|')
			&& quote_flag == 0) // handle single
		{
			tab[i++] = ft_substr(s, start, 1);
			start += 1;
		}
		else
		{
			len = 0;
			if (s[start] == '"' || s[start] == '\'')
			{
				quote_flag = s[start];
				len++; // include start quote
				while (s[start + len] && s[start + len] != quote_flag)
					len++;
				if (s[start + len] == quote_flag)
					len++; // include closing quote
			}
			else
			{
				while (s[start + len] && s[start + len] != sep && s[start
					+ len] != '<' && s[start + len] != '>' && s[start
					+ len] != '|' && s[start + len] != '"' && s[start
					+ len] != '\'')
					len++;
			}
			tab[i++] = ft_substr(s, start, len);
			start += len;
			quote_flag = 0; // reset quote flag after each word
		}
	}
	tab[i] = NULL;
}

int	ft_count_words2(char const *s, char sep)
{
	int		i;
	int		count;
	char	quote_flag;

	i = 0;
	count = 0;
	quote_flag = 0;
	while (s[i])
	{
		// Skip separators
		while (s[i] == sep)
			i++;
		if (!s[i])
			break ;
		// Double operator: << or >>
		if ((s[i] == '<' || s[i] == '>') && s[i + 1] == s[i] && quote_flag == 0)
		{
			count++;
			i += 2;
		}
		// Single operator: < > |
		else if ((s[i] == '<' || s[i] == '>' || s[i] == '|') && quote_flag == 0)
		{
			count++;
			i += 1;
		}
		else
		{
			count++;
			if (s[i] == '"' || s[i] == '\'')
			{
				quote_flag = s[i++];
				while (s[i] && s[i] != quote_flag)
					i++;
				if (s[i] == quote_flag)
					i++; // skip closing quote
				quote_flag = 0;
			}
			else
			{
				while (s[i] && s[i] != sep && s[i] != '<' && s[i] != '>'
					&& s[i] != '|' && s[i] != '"' && s[i] != '\'')
					i++;
			}
		}
	}
	return (count);
}

char	**ft_split2(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words2(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}
