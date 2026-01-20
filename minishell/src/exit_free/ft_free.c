/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:59:10 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/15 12:48:36 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_free.h"

void	free_arr(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	while (i > 0)
		free(str[--i]);
	free(str);
}
