/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:28 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/23 15:25:05 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	ft_free(t_list *lst ,char *key, char *value)
{
	t_list	*tmp;
	t_envar	*envar;

	if (key)
		free(key);
	if (value)
		free(value);
	while(lst)
	{
		tmp = lst->next;
		envar = (t_envar *)lst->content;
		if (envar)
		{
			if (envar->key)
				free(envar->key);
			if (envar->value)
				free(envar->value);
			free(envar);
		}
		free(lst);
		lst = tmp;
	}
	exit(1);
}

static	void	key_value(char *key, char *value)
{
	free(key);
	free(value);
}

void	append_export(t_list *lst, char *str)
{
	char	*key;
	char	*value;
	char	*tmp;
	int		lvalue;
	t_envar	*aux;

	lvalue = find_value(str, find_key(str));
	key = ft_substr(str, 0, find_key(str));
	value = ft_substr(str, find_key(str) + 1, lvalue - find_key(str) - 1);
	if (!key || !value)
		ft_free(lst, key, value);
	while(lst)
	{
		aux = (t_envar *)lst->content;
		if(ft_strcmp(aux->key, key) == 0)
		{
			tmp = ft_strjoin(aux->value, value);
			if (!tmp)
				ft_free(lst, key, value);
			free(aux->value);
			aux->value = tmp;
		}
		lst = lst->next;
	}
	key_value(key, value);
}

void	add_export(t_list **lst, char *str)
{
	char	*key;
	char	*value;
	int		lkey;
	t_list *node;

	lkey = find_key(str);
	key = ft_substr(str, 0, find_key(str));
	if (!key)
		fatal_error("ERROR: Failed to allocate", *lst, key, NULL);
	value = ft_substr(str, lkey + 1, find_value(str, lkey) - lkey - 1);
	if (!value)
		fatal_error("ERROR: Failed to allocate", *lst, key, value);
	node = ft_lstnew(init_envar(key, value));
	ft_lstadd_back(lst, node);
	free(key);
	free(value);
}

void	show_export(t_list *lst)
{
	t_envar	*tmp;

	while (lst)
	{
		tmp = (t_envar *)lst->content;
		printf("declare -x %s=", tmp->key);
		printf("\"%s\"",tmp->value);
		printf("\n");
		lst = lst->next;
	}
}
