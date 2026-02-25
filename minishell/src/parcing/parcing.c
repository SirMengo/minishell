/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:12:56 by xalves            #+#    #+#             */
/*   Updated: 2026/02/25 13:12:57 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//-------------------Lexer----------------------
int	lexer(void)
{
	data()->manager.cmd = ft_split_espace(data()->manager.input);
	if (data()->manager.cmd == NULL)
		return (1);
	return (0);
}

int	check_invalid_pipes(void)
{
	int	i;

	i = 0;
	if (ft_strcmp(data()->manager.cmd[0], "|") == 0)
		return (1);
	while (data()->manager.cmd[i] != NULL)
	{
		if (ft_strcmp(data()->manager.cmd[i], "|") == 0)
			if (ft_strcmp(data()->manager.cmd[0], "|") == 0)
				return (1);
		i++;
	}
	if (ft_strcmp(data()->manager.cmd[i - 1], "|") == 0)
		return (1);
	return (0);
}

//-------------------------------------------------------
int	parcing(void)
{
	if (checkunclosedquotes() == 1)
		return (1);
	if (lexer() == 1)
		return (1);
	if (checkinvalidtokens() == 1)
		return (1);
	if (check_invalid_pipes() == 1)
		return (1);
	checkforexpansion();
	preparelist();
	return (0);
}
