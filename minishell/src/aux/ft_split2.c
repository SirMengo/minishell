/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:11:56 by xalves            #+#    #+#             */
/*   Updated: 2025/09/25 17:50:19 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

static void	ft_allocate(char **tab, char const *s, char sep)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	start = 0;
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
		else if (s[start] == '<' || s[start] == '>' || s[start] == '|')
		{
			tab[i++] = ft_substr(s, start, 1);
			start += 1;
		}
		else
		{
			len = 0;
			while (s[start + len] && s[start + len] != sep && s[start
				+ len] != '<' && s[start + len] != '>' && s[start + len] != '|')
				len++;
			tab[i++] = ft_substr(s, start, len);
			start += len;
		}
	}
	tab[i] = NULL;
}

int	ft_count_words(char const *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (!s[i])
			break ;
		if ((s[i] == '<' || s[i] == '>') && s[i + 1] == s[i])
		{
			count++;
			i += 2;
		}
		else if (s[i] == '<' || s[i] == '>' || s[i] == '|')
		{
			count++;
			i++;
		}
		else
		{
			count++;
			while (s[i] && s[i] != sep && s[i] != '<' && s[i] != '>'
				&& s[i] != '|')
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}
