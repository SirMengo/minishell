/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:13:16 by xalves            #+#    #+#             */
/*   Updated: 2026/02/25 13:13:18 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//-----------Checkers--------------------------
// if (*quote_flag == 0) // Opening quote
// else if (*quote_flag == c) // Closing quote
void	checkforquotes(char c, char *quote_flag)
{
	if (c == '"' || c == '\'')
	{
		if (*quote_flag == 0)
			*quote_flag = c;
		else if (*quote_flag == c)
			*quote_flag = 0;
	}
}

//(3º if) group only pipes
//(4º if) group both < and >
int	checkfortokens(char const **s, char *quote_flag, int *word_count)
{
	if (*quote_flag != 0)
		return (0);
	if (**s == '\\')
		return (-1);
	if (**s == '|')
	{
		(*word_count)++;
		while (**s == '|')
			(*s)++;
		return (1);
	}
	if (**s == '<' || **s == '>')
	{
		(*word_count)++;
		while (**s == '<' || **s == '>')
			(*s)++;
		return (1);
	}
	return (0);
}
