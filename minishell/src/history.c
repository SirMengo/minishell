/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:09:56 by xalves            #+#    #+#             */
/*   Updated: 2026/02/25 13:10:00 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_args(void *ptr)
{
	t_args	*cmd;

	cmd = (t_args *)ptr;
	if (!cmd)
		return ;
	free_arrstr(cmd->content);
	free_arrstr(cmd->type);
	free(cmd);
}

void	free_arrstr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

// ------------Signals-------------------
void	addtohistory_andclean(void)
{
	if (data()->manager.input && data()->manager.input)
		add_history(data()->manager.input);
	if (data()->manager.cmd)
		free_arrstr(data()->manager.cmd);
	if (data()->manager.cmds)
		ft_lstclear(&data()->manager.cmds, free_args);
	free(data()->manager.input);
	data()->manager.cmd = NULL;
	data()->manager.input = NULL;
	data()->manager.cmds = NULL;
}
