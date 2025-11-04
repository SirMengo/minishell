/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:48:40 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/04 16:23:37 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

static void	free_key_value(char *key, char *value)
{
	if (key)
		free(key);
	if (value)
		free(value);
}

static int	add_parser(t_list *lst, char *st)
{
	t_envar	*aux;
	char	*key;
	char	*value;
	
	key = find_key(st);
	value = find_value(st);
	if (!key)
		return(free_key_value(key, value), 1);
	while(lst)
	{
		aux = lst->content;
		if (ft_strcmp(key, aux->key) == 0)
		{
			free(aux->value);
			if (value != NULL)
				aux->value = ft_strdup(value);
			else
				aux->value = NULL;
			free_key_value(key, value);
			return (0);
		}
		lst = lst->next;
	}
	add_export(&lst, key, value);
	return (0);
}

static int	append_parser(t_list *lst, char *st)
{
	t_envar *aux;
	char *key;
	char *value;

	key = find_key(st);
	value = find_value(st);
	while (lst)
	{
		aux = (t_envar *)lst->content;
		if (ft_strcmp(key, aux->key) == 0)
		{
			if (value == NULL || value[0] == '\0')
				return (free_key_value(key, value), 0);
			else
			{
				append_export(lst, key, value);
				return (0);
			}
		}
		lst = lst->next;
	}
	add_export(&lst, key, value);
	return (0);
}

static int	no_sign_parser(t_list *lst, char *st)
{
	t_envar	*aux;
	char	*key_copy;

	while (lst)
	{
		aux = (t_envar *)lst->content;
		if (ft_strcmp(st, aux->key) == 0)
			return (0);
		lst = lst->next;
	}
	key_copy = ft_strdup(st);
	add_export(&lst, key_copy, NULL);
	return (0);
}

int	export(t_list *lst, char *st)
{
	if (ft_findchar(st, '=') == 0)
		return (no_sign_parser(lst, st));
	else
	{
		if (is_append(st) == 1)
			return (append_parser(lst, st));
		else
			return (add_parser(lst, st));
	}
}
