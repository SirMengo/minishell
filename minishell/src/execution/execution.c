/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:09:12 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/13 12:27:27 by jobraga-         ###   ########.fr       */
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

static	void exec_binary(char *path, char **cmd, char **ev)
{
	execve(path, cmd, ev);
	err_handler("failed to execute", errno, cmd[0]);
	path_is_null(path, cmd);
}

void	cmd_exec(t_cmd **cmd, char **arg)
{
	char	*path;
	char	**ev;

	ev = conv_env();
	if (!ev)
		out_of_mem();
	if (is_builtin(arg))
	{
		clean_cmd_arr(cmd);
		free(cmd);
		free_arr(ev);
		exit_free(data()->err_code);
	}
	path = find_path(ev, arg[0]);
	if (!path)
		out_of_mem();
	if (path[0] == '\0')
	{
		err_handler("command not found", 127, arg[0]);
		path_is_null(path, arg);
	}
	if (access(path, X_OK | R_OK) == 0)
		exec_binary(path, arg, ev);
	err_handler("permission denied", 126, arg[0]);
	path_is_null(path, arg);
}
