/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_espace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:11:56 by xalves            #+#    #+#             */
/*   Updated: 2026/02/17 15:44:36 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"
//--------------------Count Words--------------------------

char const	*countwords_aux(char const *s, char sep, char *quote_flag)
{
	while (*s)
	{
		checkforquotes(*s, quote_flag);
		if (*quote_flag == 0 && (*s == '|' || *s == '<' || *s == '>'))
			break ;
		s++;
		if (*quote_flag == 0 && *s == sep)
			break ;
	}
	return (s);
}

int	ft_count_words(char const *s, char sep)
{
	int		word_count;
	char	quote_flag;
	int		ret;

	word_count = 1;
	quote_flag = 0;
	ret = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (!*s)
			break ;
		ret = checkfortokens(&s, &quote_flag, &word_count);
		if (ret == -1)
			return (printf("\nSyntax error: unexpected '\\'\n"), -1);
		if (ret == 1)
			continue ;
		word_count++;
		s = countwords_aux(s, sep, &quote_flag);
		if (s == NULL)
			return (printf("\nSyntax error: unexpected '\\'\n"), -1);
	}
	return (word_count);
}

//---------------------------------------

static int	checker_ret(int ret, char ***tab_p, char const *str, char const *s)
{
	if (ret == 1)
	{
		**tab_p = ft_substr(str, 0, s - str);
		(*tab_p)++;
		return (1);
	}
	return (0);
}

//check token first (| or <> groups)
static int	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char		quote_flag;
	int			dummy_wc;
	int			ret;
	char const	*start;

	dummy_wc = 0;
	quote_flag = 0;
	tab_p = tab;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (!*s)
			break ;
		start = s;
		ret = checkfortokens(&s, &quote_flag, &dummy_wc);
		if (checker_ret(ret, &tab_p, start, s))
			continue ;
		start = s;
		s = countwords_aux(s, sep, &quote_flag);
		*tab_p = ft_substr(start, 0, s - start);
		tab_p++;
	}
	return (*tab_p = NULL, 0);
}

char	**ft_split_espace(char const *s)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, ' ');
	printf("	%d size\n", size);
	if (size == -1)
		return (NULL);
	new = ft_calloc( (size + 1), sizeof(char *));
	if (!new)
		return (NULL);
	if (size == 1)
	{
		new[0] = ft_strdup(s);
		if (!new[0])
			return (free_arr(new), NULL);
	}
	else if (ft_allocate(new, s, ' ') == -1)
		return (NULL);
	return (new);
}
//printf("\nword_count =%d", size);
