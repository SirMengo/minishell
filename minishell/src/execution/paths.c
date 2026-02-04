/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:44:40 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/04 14:18:19 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static char	*popu_paths(char **paths, char *cmd)
{
	int		i;
	char	*path;
	char	*add_path;

	i = 0;
	while (paths[i])
	{
		add_path = ft_strjoin(paths[i], "/");
		if (!add_path)
			return (free_arr(paths), NULL);
		path = ft_strjoin(add_path, cmd);
		free(add_path);
		if (!path)
			return (free_arr(paths), NULL);
		if (access(path, F_OK) == 0)
			return (free_arr(paths), path);
		free(path);
		i++;
	}
	free_arr(paths);
	return (ft_strdup(""));
}

static int	check_absolute_path(char *cmd)
{
	struct stat	inf;
	
	if (cmd[0] == '\0')
		return (err_handler("command not found", 127, cmd));
	ft_memset(&inf, 0, sizeof(struct stat));
	if (ft_strchr(cmd, '/'))
	{
		if (stat(cmd, &inf) != 0)
		{
			if (errno == EACCES)
				return (err_handler("permission denied", 127, cmd));
			return (err_handler("no such file or directory", errno, cmd));
		}
		if (S_ISDIR(inf.st_mode) == 1)
			return (err_handler("is a directory", 126, cmd));
		if (access(cmd, F_OK) == 0)
			return (1);
		return (err_handler("no such file or directory", 127, cmd));
	}
	return (1);
}

char	*find_path(char	**envp, char *cmd)
{
	int		i;
	char	**paths;
	
	if (check_absolute_path(cmd) == 0)
		return (ft_strdup("\0"));
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (ft_strdup(""));
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (popu_paths(paths, cmd));
}
