/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_in_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:36:44 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/05 18:48:24 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	exec_in_parent(t_cmd **cmd)
{
	if (cmd[1] != NULL)
		return (0);
	if (!ft_strcmp(cmd[0]->arg[0], "cd"))
		return (cd(cmd[0]->arg), 1);
	else if (!ft_strcmp(cmd[0]->arg[0], "exit"))
		return (ft_exit(cmd[0]->arg), 1);
	else if (!ft_strcmp(cmd[0]->arg[0], "unset"))
		return (unset(cmd[0]->arg), 1);
	else if (!ft_strcmp(cmd[0]->arg[0], "export"))
		if (cmd[0]->arg[1] != NULL)
			return (export(cmd[0]->arg), 1);
	return (0);
}
