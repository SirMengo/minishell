/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:01:01 by msimoes           #+#    #+#             */
/*   Updated: 2025/09/25 17:05:15 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*check_exec(char **envs, char *name)
{
	int i;
	
	i = 0;
	while (envs[i])
	{
		ft_strjoin(envs[i], "/");
		ft_strjoin(envs[i], name);
		if (access(envs[i], F_OK | X_OK) == 0)
		{
			printf("Encontrei");
			return (envs[i]);
		}
		i++;
	}
	printf("Nao encontrei");
	return (NULL);
}

int	exec(char *name)
{
	char *aux;
	char **envs;
	int i;
	
	aux = getenv("PATH");
	envs = ft_split(aux, ':');
	i = 0;
	check_exec(envs, name);
	return (0);
}

int main(char **argv)
{
	exec(argv[1]);
}