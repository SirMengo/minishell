/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exports.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:28 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/09 11:18:56 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

void	free_key_value(char *key, char *value)
{
	if (key)
		free(key);
	if (value)
		free(value);
}

int	append_export(t_list *lst, char *key, char *value)
{
	t_envar	*aux;
	char	*temp;
	char	*new_value;

	aux = (t_envar *)lst->content;
	if (!value)
		return (free(key), 0);
	if (!aux->value)
	{
		aux->value = ft_strdup(value);
		if (!aux->value)
			return (free_key_value(key, value), 1);
	}
	else
	{
		temp = aux->value;
		new_value = ft_strjoin(temp, value);
		if (!new_value)
			return (free_key_value(key, value), 1);
		aux->value = new_value;
		free(temp);
	}
	return (free_key_value(key, value), 0);
}

int	add_export(t_list **lst, char *key, char *value)
{
	t_list	*node;
	t_envar	*envar;

	envar = init_envar(key, value);
	if (!envar)
		return (free_key_value(key, value), 1);
	node = ft_lstnew(envar);
	if (!node)
	{
		free_key_value(envar->key, envar->value);
		return (free(envar), 1);
	}
	ft_lstadd_back(lst, node);
	return (free_key_value(key, value), 0);
}

void	show_export(t_list *lst)
{
	t_envar	*tmp;

	while (lst)
	{
		tmp = (t_envar *)lst->content;
		printf("declare -x %s", tmp->key);
		if (tmp->value)
			printf("=\"%s\"\n", tmp->value);
		else
			printf("\n");
		lst = lst->next;
	}
}
