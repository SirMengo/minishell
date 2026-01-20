/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removequotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:34:40 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/16 14:41:58 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

// -------------Remove quotes--------------------

// -------------Remove quotes--------------------

void    pull_str(char *str)
{
    int    i;
    
    i = 1;
    while (str[i] != '\0')
    {
        str[i - 1] = str[i];
        i++;
    }
    str[i - 1] = '\0';
}

char *removequotes(char *str)
{
    char    flag;
    int        i;

    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '"' || str[i] == '\'')
        {
            flag = str[i];
            pull_str(&str[i]);
            while (str[i] != flag)
                i++;
            pull_str(&str[i]);
        }
        if (str[i] != '"' && str[i] != '\'')
            i++;
    }
    return (str);
}





/* char	*append_segment(char *result, const char *str, int start, int len)
{
	char	*temp;
	char	*old;

	temp = ft_substr(str, start, len);//get subtring
	if (!temp)
		return (result);
	old = result;
	result = ft_strjoin(result, temp);//join old + temp
	free(old);
	free(temp);
	return (result);
}

//ft_substr(const char *s, unsigned int start, size_t len)
char	*removequotes(char *str)
{
	char	*result;
	char	quote_flag;
	int		i;
	int		start;

	i = 0;
	start = 0;
	quote_flag = 0;
	result = ft_strdup("");
	while (str[i] != '\0')
	{
		if ((str[i] == '"' || str[i] == '\'') && \
			(quote_flag == 0 || quote_flag == str[i]))
		{
			if (i > start)
				result = append_segment(result, str, start, i - start);
			if (quote_flag == 0)
				quote_flag = str[i];
			else
				quote_flag = 0;
			start = i + 1;
		}
		i++;
	}
	if (start < i)
		result = append_segment(result, str, start, i - start);
	return (result);
} */
