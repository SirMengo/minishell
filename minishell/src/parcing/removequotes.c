/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removequotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:34:40 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/16 14:28:53 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

// -------------Remove quotes--------------------

char	*append_segment(char *result, const char *str, int start, int len)
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
}
