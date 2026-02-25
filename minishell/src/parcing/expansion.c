/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:04:06 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/25 11:15:50 by xalves           ###   ########.fr       */
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

static char	*straux_substr(char *s, int start, int i)
{
	char	*straux;

	straux = ft_substr(s, start, (i - start));
	return (straux);
}

// return string expanded
char	*handle_envarargs(char *s)
{
	char		quote_flag;
	int			start;
	int			i;
	char		*strres;

	start = 0;
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
		strres = strjoin_free_left(strres, straux_substr(s, start, i));
	return (strres);
}
