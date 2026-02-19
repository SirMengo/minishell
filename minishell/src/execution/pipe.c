/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:20:32 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/19 15:58:38 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	set_redir(t_cmd **arr, int i, int *in, int *out)
{
	*in = data()->fd_lastin;
	*out = -1;
	if (arr[i]->fd_in != 0)
		*in = arr[i]->fd_in;
	if (arr[i]->fd_out != 0)
		*out = arr[i]->fd_out;
	else if (arr[i + 1] != NULL)
		*out = arr[i]->fd_pipe[1];
}

void	exec_child(t_cmd **arr, int i)
{
	int		in;
	int		out;
	bool	fail;

	in = 0;
	out = 0;
	fail = false;
	set_redir(arr, i, &in, &out);
	if (dup2(in, STDIN_FILENO) == -1)
		fail = true;
	else if (out != -1 && dup2(out, STDOUT_FILENO) == -1)
		fail = true;
	close(data()->fd_lastin);
	if (fail == true)
		exit_error();
	close_fds(arr);
	cmd_exec(arr[i]->arg, arr[i]->fd_pipe);
}

void	exec_pipe(t_cmd **arr, int i)
{
	if (pipe(arr[i]->fd_pipe) == -1)
		exit_error();
	dprintf(2, "command: %s\n",arr[i]->arg[0]);
	dprintf(2, "pipes 1: %d\n",arr[i]->fd_pipe[0]);
	dprintf(2, "pipes 2: %d\n",arr[i]->fd_pipe[1]);
	if (arr[i]->execute)
	{
		arr[i]->pid = fork();
		if (arr[i]->pid == -1)
		{
			close_pipes(arr[i]->fd_pipe);
			exit_error();
		}
	}
	if (arr[i]->pid == 0)
		exec_child(arr, i);
	else
	{
		close(data()->fd_lastin);
		data()->fd_lastin = arr[i]->fd_pipe[0];
		close(arr[i]->fd_pipe[1]);
	}
}

int	pipes(t_cmd **arr)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	data()->in_child = true;
	data()->fd_lastin = dup(STDIN_FILENO);
	if (data()->fd_lastin == -1)
		exit_error();
	while (arr[i] != NULL)
	{
		exec_pipe(arr, i);
		i++;
	}
	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i]->execute)
		{
			waitpid(arr[i]->pid, &status, 0);
			if (WIFEXITED(status))
				cmd_error(WEXITSTATUS(status));
		}
		i++;
	}
	return (close(data()->fd_lastin), 0);
}
