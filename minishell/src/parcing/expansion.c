/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:04:06 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/21 16:06:55 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//dont know if the slash is a problem
int	checkfordolar(char *str)
{
	int		i;
	char	quote_flag;

	i = 0;
	quote_flag = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '"') || (str[i] == '\''))
		{
			if (quote_flag != 0 && quote_flag == str[i])
				quote_flag = 0;
			else if (quote_flag == 0)
				quote_flag = get_quote_flag(str[i]);
		}
		if ((str[i] == '$' && quote_flag == 0) \
	|| (str[i] == '$' && quote_flag == '"'))
			return (1);
		i++;
	}
	return (0);
}

// Valid characters for envars
	// - Letters: a-z, A-Z
	// - Digits: 0-9
	// - Underscore: '_'
int	invalid_envar_c(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	if (c == '_')
		return (0);
	return (1);
}

//handle_envarargs aux
static char	*append_segment(char *res, char *s, int start, int len)
{
	char	*tmp;

	if (len <= 0)
		return (res);
	tmp = ft_substr(s, start, len);
	return (strjoin_free_left(res, tmp));
}

//handle_envarargs aux
static char	*handle_dollar(char *res, char *s, int *start, int *i)
{
	res = append_segment(res, s, *start, *i - *start);
	*start = *i;
	res = strjoin_free_left(res, getenvarval(s, *start, i));
	*start = *i;
	return (res);
}

// return string expanded
char	*handle_envarargs(char *s)
{
	char		quote_flag;
	static int	start;
	int			i;
	char		*strres;
	char		*straux;

	quote_flag = 0;
	i = 0;
	strres = ft_strdup("");
	while (s[i] != '\0')
	{
		checkforquotes(s[i], &quote_flag);
		if (s[i] == '$' && quote_flag != '\'')
		{
			strres = handle_dollar(strres, s, &start, &i);
			continue ;
		}
		i++;
	}
	if (start < i)
	{
		straux = ft_substr(s, start, (i - start));
		strres = strjoin_free_left(strres, straux);
	}
	return (strres);
}
