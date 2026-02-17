/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:23:06 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/17 14:18:59 by msimoes          ###   ########.fr       */
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

//-------------------------------------------------------
int	parcing()
{
	if (checkunclosedquotes() == 1)
		return (1);
	if (lexer() == 1)
		return (1);
	if (checkinvalidtokens() == 1)
		return (1);
	checkforexpansion();
	preparelist();
	return (0);
}
