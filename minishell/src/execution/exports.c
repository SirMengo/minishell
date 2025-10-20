/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:28 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/20 15:25:36 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	append_export(t_envar *lst, char *str)
{
	char *key;
	char *value;
	
	key = NULL;
	value = NULL;
	while(lst)
	{
		if (lst->name == key)
		{
			ft_strjoin(lst->name, str);
		}
		lst = lst->next;
	}
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
		printf("declare -x %s=", lst->name);
		printf("%s",lst->value);
		printf("\n");
		lst = lst->next;
	}
}

void	exports(t_envar	*lst)
{
	int		i;
	char	str[8] = "AAA=BBB";
	char	str2[8] = "AAA=CCC";

	
	i = 0;
	add_export(&lst, str);
	show_export(lst);
	printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	append_export(lst, str2);
	show_export(lst);
	//if str = example=example <- se 'example' ja existe, atualizar
	//senao, criar um novo ponto na lista
	//if str = example <- se 'example' existe, nao fazer nada
	//se nao, criar example sem valor 
	/*if (ft_strlen(str) == 6)
	{
	}*/
}
