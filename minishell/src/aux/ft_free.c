/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:59:10 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/20 15:12:05 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
		free(str[--i]);
	free(str);
}

void	free_command(void *ptr)
{
	t_command	*cmd;

	if (!ptr)
		return ;
	cmd = (t_command *)ptr;
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->args)
		free_arr(cmd->args);
	free(cmd);
}
