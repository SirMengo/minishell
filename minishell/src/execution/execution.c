/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:09:12 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/25 13:05:38 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static	void	path_is_null(char *path, char **ev)
{
	free_arr(ev);
	free(path);
	exit_free(data()->err_code);
}

static	void	out_of_mem(void)
{
	err_handler("out of memory", ENOMEM, NULL);
	exit_free(data()->err_code);
}

static	void	exec_binary(char *path, char **cmd, char **ev)
{
	execve(path, cmd, ev);
	err_handler("failed to execute", errno, cmd[0]);
	path_is_null(path, ev);
}

static void	cmd_aux(char *path, char **arg, char **ev)
{
	if (access(path, X_OK | R_OK) == 0)
		exec_binary(path, arg, ev);
	err_handler("Permission denied", 126, arg[0]);
	path_is_null(path, ev);
}

void	cmd_exec(char **arg, int fd_pipe[2])
{
	char	*path;
	char	**ev;
	bool	failed_abs;

	failed_abs = false;
	toggle_sig_quit();
	if (is_builtin(arg))
	{
		close_pipes(fd_pipe);
		exit_free(data()->err_code);
	}
	close_pipes(fd_pipe);
	ev = conv_env();
	if (!ev)
		out_of_mem();
	path = find_path(ev, arg[0], &failed_abs);
	if (!path)
		out_of_mem();
	if (path[0] == '\0')
	{
		if (failed_abs == false)
			err_handler("command not found", 127, arg[0]);
		path_is_null(path, ev);
	}
	cmd_aux(path, arg, ev);
}
