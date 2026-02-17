/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:03:06 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/13 12:29:27 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_free.h"

void	free_lists()
{	
	ft_lstclear(&data()->env, free_env);
}

static void	ft_freeall()
{
	free_arr(data()->manager.cmd);
	free_lists();
}

void	exit_error()
{
	perror("Minihorse");
	exit_free(errno);
}

void	exit_free(int err)
{
	ft_freeall();
	exit(err);
}
