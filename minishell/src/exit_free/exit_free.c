/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:03:06 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/14 12:13:41 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_free.h"

void	free_lists()
{	
	ft_lstclear(data()->env, free_env);
}

void	ft_freeall()
{
	free_lists();
}

void	exit_free(int err)
{
	ft_freeall();
	exit(err);
}
