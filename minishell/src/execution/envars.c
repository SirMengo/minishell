/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envars.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:11:19 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/22 14:59:00 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

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

int	count_envars(char **envars)
{
	int	i;

	i = 0;
	while (envars[i])
		i++;
	return (i);
}

void	create_lst(t_list **lst, char **ev)
{
	char	*key;
	char	*value;
	int		i;
	int		lkey;

	i = 0;
	lkey = 0;
	key = NULL;
	value = NULL;
	while (ev[i])
	{
		lkey = find_key(ev[i]);
		key = ft_substr(ev[i], 0, lkey);
		if (!key)
			fatal_error("ERROR: Failed to allocate", *lst, key, value);
		value = ft_substr(ev[i], lkey + 1, find_value(ev[i], lkey) - lkey - 1);
		if (!value)
			fatal_error("ERROR: Failed to allocate", *lst, key, value);
		ft_lstadd_back(lst, ft_lstnew(init_envar(key, value)));
		i++;
		free(key);
		free(value);
	}
}

void	show_envars(t_list *lst)
{
	t_envar *tmp;
	
	while(lst)
	{
		tmp = (t_envar *)lst->content;
		printf("%s=\"%s\"\n", tmp->key, tmp->value);
		lst = lst->next;
	}
}
