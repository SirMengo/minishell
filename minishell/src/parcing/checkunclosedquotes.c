/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkunclosedquotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:42:36 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/25 11:14:29 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//--------------UnclosedQuotes-----------------

// get which quote we got and return it
// If the argument starts with a quote, 
//we're inside that quote type
char	get_quote_flag(char c)
{
	if (c == '"')
		return ('"');
	if (c == '\'')
		return ('\'');
	return (0);
}

// print syntax error
int	print_unclosedquotes_error(void)
{
	printf("\nSyntax error: unclosed quotes\n");
	return (1);
}

int	print_backslash_error(void)
{
	printf("\nSyntax error: backslash\n");
	return (1);
}

// Search for closing quote untill quote or \0
int	checkunclosedquotes(void)
{
	int		i;
	char	quote_flag;

	i = 0;
	quote_flag = 0;
	while (data()->manager.input[i] != '\0')
	{
		if ((data()->manager.input[i] == '"') \
|| (data()->manager.input[i] == '\''))
		{
			if (quote_flag != 0 && quote_flag == data()->manager.input[i])
				quote_flag = 0;
			else if (quote_flag == 0)
				quote_flag = get_quote_flag(data()->manager.input[i]);
		}
		if (data()->manager.input[i] == '\\' && quote_flag == 0)
			return (print_backslash_error());
		i++;
	}
	if (quote_flag != 0)
		return (print_unclosedquotes_error());
	return (0);
}
