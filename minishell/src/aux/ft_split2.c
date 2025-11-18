/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:11:56 by xalves            #+#    #+#             */
/*   Updated: 2025/11/18 11:12:15 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

static void	ft_allocate(char **tab, const char *s, char sep)
{
	int		i;
	int		start;
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
		if ((s[start] == '<' || s[start] == '>') && s[start + 1] == s[start])
		{
			tab[i++] = ft_substr(s, start, 2);
			start += 2;
		}
		else if (is_special(s[start]) && quote_flag == 0 && s[start] != '"' && s[start] != '\'')
		{
			tab[i++] = ft_substr(s, start, 1);
			start++;
		}
		else
			start += handle_word(&tab[i++], s, start, sep);
	}
	tab[i] = NULL;
}

//-------------------------------------------------------------
int	ft_count_words2(char const *s, char sep, int *error_flag)
{
	int		i;
	int		count;
	char	quote_flag;

	i = 0;
	count = 0;
	quote_flag = 0;
	*error_flag = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (!s[i])
			break ;
		if ((s[i] == '<' || s[i] == '>') && s[i + 1] == s[i] && quote_flag == 0)
		{
			count++;
			i += 2;
		}
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
				if (s[i] == '\0')
				{
					*error_flag = 1; // set error
					return (count);
				}
				i++;
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


char **ft_split2(char const *s, char c)
{
	char	**new;
	int		size;
	int		error_flag;

	if (!s)
		return (NULL);
	size = ft_count_words2(s, c, &error_flag);
	if (error_flag)
	{
		printf("Syntax error: unclosed quotes\n");
		return (NULL); // donâ€™t allocate anything
	}
	new = malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}