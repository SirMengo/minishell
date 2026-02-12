/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:59:10 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/12 17:23:59 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

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
