/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envars.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:11:19 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/19 14:24:16 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static void	fatal_error(const char *msg, char *key, char *value)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	if (key)
		free(key);
	if (value)
		free(value);
	if (data()->env)
		ft_lstclear(&data()->env, free_envar);
	exit(1);
}

void	free_envar(void *content)
{
	t_envar *tmp;

	if (!content)
		return ;
	tmp = (t_envar *)content;
	if (tmp->key)
		free(tmp->key);
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}

char	*find_envar(char *str)
{
	t_envar *tmp;
	t_list	*lst;

	lst = data()->env;
	while (lst)
	{
		tmp = (t_envar *)lst->content;
		if (ft_strcmp(tmp->key, str) == 0)
			return (tmp->value);
		lst = lst->next;
	}
	return (NULL);
}

void	show_envars(void)
{
	t_envar *tmp;
	t_list	*lst;
	
	lst = data()->env;
	while(lst)
	{
		tmp = (t_envar *)lst->content;
		if (tmp->value != NULL)
			printf("%s=%s\n", tmp->key, tmp->value);
		lst = lst->next;
	}
}

void	create_lst(char **ev)
{
	t_envar	*envar;
	t_list	*node;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (ev[i])
	{
		key = find_key(ev[i]);
		value = find_value(ev[i]);
		if (!key || !value)
			fatal_error("ERROR: Failed to allocate", key, value);
		envar = init_envar(key, value);
		if (!envar)
			fatal_error("Error: Failed to allocate", key, value);
		node = ft_lstnew(envar);
		if (!node)
			fatal_error("ERROR: Failed to allocate", key, value);
		ft_lstadd_back(&data()->env, node);
		i++;
		free(key);
		free(value);
	}
}
