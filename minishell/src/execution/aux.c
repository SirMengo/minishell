/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:16:54 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/25 13:11:50 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static	int	convert(char **matrix)
{
	t_list	*env;
	t_envar	*node;
	int		i;
	char	*tmp;

	env = data()->env;
	i = 0;
	while (env)
	{
		node = env->content;
		tmp = ft_strjoin(node->key, "=");
		matrix[i] = ft_strjoin(tmp, node->value);
		free(tmp);
		if (matrix[i] == NULL)
			return (0);
		env = env->next;
		i++;
	}
	matrix[i] = NULL;
	return (1);
}

char	**conv_env(void)
{
	char	**matrix;
	t_list	*env;

	env = data()->env;
	matrix = ft_calloc(ft_lstsize(env) + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	if (!convert(matrix))
	{
		free_arr(matrix);
		return (NULL);
	}
	return (matrix);
}
