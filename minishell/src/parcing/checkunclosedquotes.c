/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkunclosedquotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:42:36 by vampaier2         #+#    #+#             */
/*   Updated: 2025/12/02 12:16:27 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//--------------UnclosedQuotes-----------------

// get which quote we got and return it
char	get_quote_flag(char c)
{
	// If the argument starts with a quote, we're inside that quote type
	if (c == '"')
		return ('"');
	if (c == '\'')
		return ('\'');
	return (0);
}

// print syntax error
int print_unclosedquotes_error()
{
    printf("\nSyntax error: unclosed quotes\n");
	return (1);
}
int print_backSlash_error()
{
    printf("\nSyntax error: backslash\n");
	return (1);
}

// Search for closing quote untill quote or \0
int checkunclosedquotes(t_manager *m)
{
    int		i;
    char	quote_flag;
    
	i = 0;
    quote_flag = 0;
	while(m->input[i] != '\0')
    {
		if((m->input[i] == '"') || (m->input[i] == '\''))
        {
            if(quote_flag != 0 && quote_flag == m->input[i])
                quote_flag = 0;
            else if(quote_flag == 0)
                quote_flag = get_quote_flag(m->input[i]);
        }
        if(m->input[i] == '\\' && quote_flag == 0)
            return(print_backSlash_error());
        i++;
    }
    if(quote_flag != 0)
        return(print_unclosedquotes_error());
    return(0);
}
