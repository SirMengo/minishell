/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removequotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:13:12 by xalves            #+#    #+#             */
/*   Updated: 2026/02/25 13:13:14 by xalves           ###   ########.fr       */
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
