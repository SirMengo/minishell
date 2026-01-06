/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:09:12 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/18 14:54:30 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

// Pode causar problema porcausa de retorno dos builtins, se eles retornarem algo sem ser 0 lixa isto tudo e nao conseguimos ver porque
int is_builtin(char *str, t_list *lst)
{
	if(ft_strcmp("cd", str) == 1)
		return (cd(lst, str[1]), 1);
	if(ft_strcmp("echo", str) == 1)
		return (echo(str), 1);
	//if(ft_strcmp("env", str) == 1)
		//return (cd(lst, str));
	if(ft_strcmp("exit", str) == 1)
		return (ft_exit(str), 1);
	if(ft_strcmp("export", str) == 1)
		return (cd(lst, str), 1);
	if(ft_strcmp("pwd", str) == 1)
		return (pwd(), 1);
	if(ft_strcmp("unset", str) == 1)
		return (unset(lst, str), 1);
	return (0);
}

int	not_found(char **cmd)
{
	ft_printerror("MiniHorse: %s: command not found", cmd[0]);
	free_arr(cmd);
	return (127);
}

static char	*popu_paths(char **paths, char *cmd, char *path, char *add_path)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		add_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(add_path, cmd);
		free(add_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			free(cmd);
			free_str(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_str(paths);
	free(cmd);
	return (NULL);
}

static char	*find_path(char	*envp[], char *cmd)
{
	int		i;
	char	**paths;
	char	*path;
	char	*add_path;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	path = NULL;
	add_path = NULL;
	i = 0;
	if (!envp && !*envp)
		error();
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (popu_paths(paths, cmd, path, add_path));
	return (cmd);
}

void	cmd_exec(char *str, char **ev, t_list lst)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(av, ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		not_found(cmd);
	path = find_path(ev, cmd[0]);
	if (!path)
		not_found(cmd);
	if (path == cmd[0] && !ft_strchr(cmd[0], '/'))
		not_found(cmd);
	if (is_builtin(str, lst))
	if (execve(path, cmd, ev) == -1)
	{
		free_str(cmd);
		error();
	}
}
