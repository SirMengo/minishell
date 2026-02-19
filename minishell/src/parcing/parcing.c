/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:23:06 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/19 16:51:57 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//-------------------Lexer----------------------
int	lexer()
{
	data()->manager.cmd = ft_split_espace(data()->manager.input);
	if (data()->manager.cmd == NULL)
		return (1);
	return (0);
}

int	check_invalid_pipes()
{
	int	i;

	i = 0;
	if(ft_strcmp(data()->manager.cmd[0], "|") == 0)
		return (1);
	while(data()->manager.cmd[i] != NULL)
	{
		if(ft_strcmp(data()->manager.cmd[i], "|") == 0)
			if(ft_strcmp(data()->manager.cmd[0], "|") == 0)
				return (1);
		i++;
	}
	if(ft_strcmp(data()->manager.cmd[i - 1], "|") == 0)
		return (1);
	return (0);
}

//-------------------------------------------------------
int	parcing()
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
