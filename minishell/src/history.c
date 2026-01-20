/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:32:06 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/20 14:21:21 by vampaier2        ###   ########.fr       */
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

void	addtohistory_andclean(t_manager *manager)
{
	if (manager->input && *manager->input)
		add_history(manager->input);
	if (manager->cmd)
		free_arrstr(manager->cmd);
	if (manager->cmds)
		ft_lstclear(&manager->cmds, free_args);
	free(manager->input);
	manager->cmd = NULL;
	manager->input = NULL;
	manager->cmds = NULL;
}
