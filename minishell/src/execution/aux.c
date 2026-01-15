/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:16:54 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/15 12:46:28 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static	int	convert(char **matrix)
{
	t_list	*env;
	t_envar	*node;
	int		i;
	
	env = data()->env;
	i = 0;
	while (env)
	{
		node = env->content;
		matrix[i] = ft_strjoin(node->key, node->value);
		if (matrix[i] == NULL)
			return (0);
		env = env->next;
		i++;
	}
	matrix[i] = NULL;
	return (1);
}

char	**conv_env()
{
	char	**matrix;
	t_list	*env;
	int		size;
	
	env = data()->env;
	size = 0;
	while(env)
	{
		env = env->next;
		size++;
	}
	matrix = ft_calloc(size + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	if (!convert(matrix))
	{
		free_arr(matrix);
		return (NULL);
	}
	return (matrix);
}
