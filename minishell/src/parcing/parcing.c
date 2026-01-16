/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:23:06 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/12 16:46:54 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//-------------------Lexer----------------------
int	lexer(t_manager *manager)
{
	manager->cmd = ft_split_espace(manager->input);
	if (manager->cmd == NULL)
		return (1);
	return (0);
}


//-------------------------------------------------------
int	parcing(t_manager *manager)
{
	if (checkunclosedquotes(manager) == 1)
		return (1);
	if (lexer(manager) == 1)
		return (1);
	if (checkinvalidtokens(manager) == 1)
		return (1);
	checkforexpansion(manager);
	return (0);
}
