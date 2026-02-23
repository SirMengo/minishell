/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:03:06 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/22 16:59:16 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_free.h"

void	free_lists(void)
{
	ft_lstclear(&data()->env, free_env);
}

static void	ft_freeall(void)
{
	free_arr(data()->manager.cmd);
	rl_clear_history();
	clean_cmd_arr();
	free_lists();
}

void	exit_error(void)
{
	perror("Minihorse");
	ft_freeall();
	exit_free(errno);
}

void	exit_free(int err)
{
	ft_freeall();
	exit(err);
}
