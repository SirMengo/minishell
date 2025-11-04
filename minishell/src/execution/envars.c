/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envars.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:11:19 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/04 14:20:09 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	fatal_error(const char *msg, t_list *lst, char *key, char *value)
{
	t_list	*tmp;

	write(2, msg, ft_strlen(msg));
	write(2, "/n", 1);
	if (key)
		free(key);
	if (value)
		free(value);
	if (lst)
		ft_lstclear(&tmp, free_envar);
	exit(1);
}

void	free_envar(void *content)
{
	t_envar *tmp;

	if (!content)
		return ;
	tmp = (t_envar *)content;
	if (tmp->key);
		free(tmp->key);
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}

char	*find_envar(t_list *lst, char *str)
{
	t_envar *tmp;
	while (lst)
	{
		tmp = (t_envar *)lst->content;
		if (ft_strcmp(tmp->key, str) == 0)
			return (tmp->value);
		lst = lst->next;
	}
	return (NULL);
}

void	show_envars(t_list *lst)
{
	t_envar *tmp;
	
	while(lst)
	{
		tmp = (t_envar *)lst->content;
		if (tmp->value != NULL)
			printf("%s=\"%s\"\n", tmp->key, tmp->value);
		lst = lst->next;
	}
}

void	create_lst(t_list **lst, char **ev)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	key = NULL;
	value = NULL;
	while (ev[i])
	{
		key = find_key(ev[i]);
		if (!key)
			fatal_error("ERROR: Failed to allocate", *lst, key, value);
		value = find_value(ev[i]);
		if (!value)
			fatal_error("ERROR: Failed to allocate", *lst, key, value);
		ft_lstadd_back(lst, ft_lstnew(init_envar(key, value)));
		i++;
		free(key);
		free(value);
	}
}
