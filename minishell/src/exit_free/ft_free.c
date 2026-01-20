/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:59:10 by msimoes           #+#    #+#             */
<<<<<<< HEAD:minishell/src/aux/ft_free.c
/*   Updated: 2025/12/16 14:24:23 by vampaier2        ###   ########.fr       */
=======
/*   Updated: 2026/01/15 12:48:36 by msimoes          ###   ########.fr       */
>>>>>>> execution:minishell/src/exit_free/ft_free.c
/*                                                                            */
/* ************************************************************************** */

#include "exit_free.h"

void	free_arr(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	while (i > 0)
		free(str[--i]);
	free(str);
}
<<<<<<< HEAD:minishell/src/aux/ft_free.c

void	free_command(void *ptr)
{
	t_command *cmd;

	if (!ptr)
		return;
	cmd = (t_command *)ptr;
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->args)
		free_arr(cmd->args);
	free(cmd);
}

=======
>>>>>>> execution:minishell/src/exit_free/ft_free.c
