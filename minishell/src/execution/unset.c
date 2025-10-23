/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:15:20 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/23 15:24:36 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	key_value(void *content)
{
	t_envar *env;

	env = (t_envar *)content;
	free(env->key);
	free(env->value);
}

void	unset(t_list **lst, char *str)
{
	t_envar	*tmp;
	t_list	*aux;
	t_list 	*next;
	int lkey;
	char *key;

	lkey = find_key(str);
	key = ft_substr(str, 0, lkey);
	aux = *lst;
	while(aux)
	{
		next = aux->next;
		tmp = (t_envar *)aux->content;
		if(ft_strcmp(key, tmp->key) == 0)
			ft_lstdelone(lst, aux, key_value);
		aux = next;
	}
	free(key);
}

