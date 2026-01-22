/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removequotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:34:40 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/21 11:03:45 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

// -------------Remove quotes--------------------

void	pull_str(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		str[i - 1] = str[i];
		i++;
	}
	str[i - 1] = '\0';
}

char	*removequotes(char *str)
{
	char	flag;
	int		i;

	i = 0;
	while (str[i] != '\0')
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
