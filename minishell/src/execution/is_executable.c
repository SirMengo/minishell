/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:01:01 by msimoes           #+#    #+#             */
/*   Updated: 2025/09/30 15:30:12 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char *is_executable(char *cmd)
{
	int		i;
	char 	*envs;
	char	*full_path;
	char	*temp;
	char	**paths;
	
	i = 0;
	envs = getenv("PATH");
	paths = ft_split(envs, ':');
	while(paths[i++])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_arr(paths);
			return (full_path);
		}
		free(full_path);
	}
	free_arr(paths);
	return (NULL);
}

int	exec(char *name)
{
	char *aux;
	char **envs;

	aux = getenv("PATH");
	envs = ft_split(aux, ':');
	check_exec(envs, name);
	return (0);
}

/* int main(char **argv)
{
	exec(argv[1]);
} */
