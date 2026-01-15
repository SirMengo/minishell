/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:09:12 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/15 12:48:07 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static	void path_is_null(char *path, char **cmd)
{
	free_arr(cmd);
	free(path);
	exit_free(data()->err_code);
}

static	void out_of_mem()
{
	err_handler("out of memory", ENOMEM, NULL);
	exit_free(data()->err_code);
}

void	cmd_exec(char *str, char **ev)
{
	char	*path;
	char	**cmd;

	if (is_builtin(str))
		exit_free(data()->err_code);
	cmd = ft_split(str, ' ');
	if (!cmd)
		out_of_mem();
	path = find_path(ev, cmd[0]);
	if (!path)
	{
		free_arr(cmd);
		out_of_mem();
	}
	if (path[0] == '\0')
		path_is_null(path, cmd);
	if (access(path, X_OK | R_OK) != 0)
	{
		err_handler("permission denied", 126, cmd[0]);
		path_is_null(path, cmd);
	}
	execve(path, cmd, ev);
	err_handler("failed to execute", errno, cmd[0]);
	path_is_null(path, cmd);
}
