/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:32:06 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/14 13:09:51 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_args(void *ptr)
{
	t_args *args;

	if (!ptr)
		return ;
	args = (t_args *)ptr;
	if (args->content)
		free(args->content);
	// Don't free args->type - it points to string literals like "pipe", "arg"
	free(args);
}

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
// ------------Signals-------------------

void	addtohistory_andclean(t_manager *manager)
{
	if (manager->input && *manager->input)
		add_history(manager->input);
	if (manager->cmd)
		free_argv(manager->cmd);
	if (manager->cmds)
		ft_lstclear(&manager->cmds, free_args);
	free(manager->input);
	manager->cmd = NULL;
	manager->input = NULL;
	manager->cmds = NULL;
}
