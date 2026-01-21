/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:15:20 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/20 16:14:49 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static	void	key_value(void *content)
{
	t_envar	*env;

	env = (t_envar *)content;
	free(env->key);
	free(env->value);
	free(env);
}

void	unset(char **arr)
{
	t_envar	*tmp;
	t_list	*aux;
	t_list	*next;
	char	*key;

	key = find_key(arr[1]);
	if (!key)
		return ;
	aux = data()->env;
	while (aux)
	{
		next = aux->next;
		tmp = (t_envar *)aux->content;
		if (ft_strcmp(key, tmp->key) == 0)
			ft_lstdelone(&data()->env, aux, key_value);
		aux = next;
	}
	free(key);
}
