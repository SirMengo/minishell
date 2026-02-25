/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:03:06 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/25 13:12:02 by xalves           ###   ########.fr       */
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
