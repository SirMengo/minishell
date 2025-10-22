/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:28 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/21 16:19:30 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	ft_free(t_envar *lst ,char *key, char *value, char *tmp)
{
	t_envar *next;

	if (key)
		free(key);
	if (value)
		free(value);
	if (tmp)
		free(tmp);
	while(lst)
	{
		next = lst->next;
		if (lst->key)
			free(lst->key);
		if (lst->value)
			free(lst->value);
		free(lst);
		lst = next;
	}
	exit(1);
}

void	append_export(t_envar *lst, char *str)
{
	char	*key;
	char	*value;
	char	*tmp;
	int		lvalue;

	lvalue = find_value(str, find_key(str));
	key = ft_substr(str, 0, find_key(str));
	value = ft_substr(str, find_key(str) + 1, lvalue - find_key(str) - 1);
	if (!key || !value)
		ft_free(lst, key, value, NULL);
	while(lst)
	{
		if(ft_strcmp(lst->key, key) == 0)
		{
			tmp = ft_strjoin(lst->value, value);
			if (!tmp)
				ft_free(lst, key, value, NULL);
			free(lst->value);
			lst->value = tmp;
			break;
		}
		lst = lst->next;
	}
	free(key);
	free(value);
}

void	add_export(t_envar **lst, char *str)
{
	char	*key;
	char	*value;
	int		lkey;
	t_envar *node;

	lkey = find_key(str);
	key = ft_substr(str, 0, find_key(str));
	if (!key)
		fatal_error("ERROR: Failed to allocate", *lst, key, value);
	value = ft_substr(str, lkey + 1, find_value(str, lkey) - lkey - 1);
	if (!value)
		fatal_error("ERROR: Failed to allocate", *lst, key, value);
	node = ft_lstnew(ft_strdup(key), ft_strdup(value));
	ft_lstadd_back(lst, node);
	free(key);
	free(value);
}

void	show_export(t_envar *lst)
{
	while (lst)
	{
		printf("declare -x %s=", lst->key);
		printf("\"%s\"",lst->value);
		printf("\n");
		lst = lst->next;
	}
}

void	exports(t_envar	*lst)
{
	int		i;
	char	str[4] = "A=B";
	char	str2[4] = "A=C";

	i = 0;
	add_export(&lst, str);
	show_export(lst);
	printf("\n\n\n\n\n");
	append_export(lst, str2);
	show_export(lst);
	unset(lst, str);
	printf("\n\n\n\n\n");
	show_export(lst);
	//if str = example=example <- se 'example' ja existe, atualizar
	//senao, criar um novo ponto na lista
	//if str = example <- se 'example' existe, nao fazer nada
	//se nao, criar example sem valor
	/*if (ft_strlen(str) == 6)
	{
	}*/
}
