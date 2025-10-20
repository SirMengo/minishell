/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envars.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:11:19 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/20 11:34:05 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	fatal_error(const char *msg, t_envar *lst, char *key, char *value)
{
	t_envar	*tmp;

	write(2, msg, ft_strlen(msg));
	write(2, "/n", 1);
	if (key)
		free(key);
	if (value)
		free(value);
	while (lst)
	{
		tmp = lst->next;
		if (lst->name)
			free(lst->name);
		if (lst->value)
			free(lst->value);
		free(lst);
		lst = tmp;
	}
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

void	create_lst(t_envar **lst, char **ev)
{
	char	*key;
	char	*value;
	int		i;
	int		lkey;
	t_envar	*node;

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
		node = ft_lstnew(ft_strdup(key), ft_strdup(value));
		ft_lstadd_back(lst, node);
		i++;
		free(key);
		free(value);
	}
}
