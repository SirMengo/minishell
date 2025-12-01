/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:24:59 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/01 13:36:02 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int update_existing(t_envar *aux, char *key, char *value)
{
	free(aux->value);
	if (value)
	{
		aux->value = ft_strdup(value);
		if (!aux->value)
			return (free_key_value(key, value), 1);
	}
	else
		aux->value = NULL;
	return (free_key_value(key, value), 0);
}

int add_parser(t_list **lst, char *st)
{
	t_envar	*aux;
	t_list	*current;
	char	*key;
	char	*value;

	key = find_key(st);
	value = find_value(st);
	if (!key)
		return (free_key_value(key, value), 1);
	current = *lst;
	while (current)
	{
		aux = current->content;
		if (ft_strcmp(key, aux->key) == 0)
			return (update_existing(aux, key, value));
		current = current->next;
	}
	return (add_export(lst, key, value));
}
