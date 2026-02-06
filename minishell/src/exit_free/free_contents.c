/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_contents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:07 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/06 15:41:01 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_free.h"

void	free_env(void *content)
{
	t_envar	*env;
	
	env = content;
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}

void	close_fds(t_cmd **contents)
{
	int	i;

	i = 0;
	while(contents[i])
	{
		if (contents[i]->fd_in && contents[i]->fd_in != -1)
			close(contents[i]->fd_in);
		if (contents[i]->fd_out && contents[i]->fd_out != -1)
			close(contents[i]->fd_out);
		i++;
	}
}
