/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenschecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:32:22 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/04 12:19:49 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//----------------Tokens-----------------------

int	checktokenstr(int idx, char firstchar)
{
	if (firstchar == '|')
		if (ft_strcmp("|", data()->manager.cmd[idx]) == 0)
			return (0);
	if (firstchar == '<')
	{
		if (ft_strcmp("<", data()->manager.cmd[idx]) == 0)
			return (0);
		else if (ft_strcmp("<<", data()->manager.cmd[idx]) == 0)
			return (0);
	}
	if (firstchar == '>')
	{
		if (ft_strcmp(">", data()->manager.cmd[idx]) == 0)
			return (0);
		else if (ft_strcmp(">>", data()->manager.cmd[idx]) == 0)
			return (0);
	}
	return (printf("\nInvalid Token!!!\n"), 1);
}

int	checkinvalidtokens()
{
	int		i;
	char	firstchar;

	i = 0;
	while (data()->manager.cmd[i] != NULL)
	{
		firstchar = data()->manager.cmd[i][0];
		if (firstchar == '|' || firstchar == '<' || firstchar == '>')
			if (checktokenstr(i, firstchar) == 1)
				return (1);
		i++;
	}
	return (0);
}
