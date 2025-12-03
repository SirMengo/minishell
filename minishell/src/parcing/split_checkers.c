/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:03:53 by vampaier2         #+#    #+#             */
/*   Updated: 2025/12/02 12:06:05 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//-----------Checkers--------------------------
void    checkforquotes(char c, char *quote_flag)
{
    if (c == '"' || c == '\'')
    {
        if (*quote_flag == 0)          // Opening quote
            *quote_flag = c;
        else if (*quote_flag == c)     // Closing quote
            *quote_flag = 0;
    }
}

int checkfortokens(char const **s, char *quote_flag, int *word_count)
{
    if (*quote_flag != 0)
        return 0;
    if (**s == '\\')
        return -1;
    if (**s == '|')
    {
        (*word_count)++;
        while (**s == '|')   // group only pipes
            (*s)++;
        return 1;
    }
    if (**s == '<' || **s == '>')
    {
        (*word_count)++;
        while (**s == '<' || **s == '>')  // group both < and >
            (*s)++;

        return 1;
    }
    return 0;
}
