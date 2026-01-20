/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:28:53 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/16 14:40:32 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdocs.h"

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

char *remove_quotes(char *str)
{
	char	flag;
	int		i;

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
