/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:28 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/06 15:25:03 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int	ft_free(t_list *lst ,char *key, char *value)
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

void	append_export(t_list *lst, char *key, char *value)
{
	t_envar *aux;
	char	*temp;

	while(lst)
	{
		aux = (t_envar *)lst->content; 
		if (ft_strcmp(aux->key, key) == 0)
		{
			temp = aux->value;
			aux->value = ft_strjoin(temp, value);
			free(temp);
			free(key);
			free(value);
			return ;
		}
		lst = lst->next;
	}
	free(key);
	free(value);
}

void	add_export(t_list **lst, char *key, char *value)
{
	t_list *node;

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
		printf("declare -x %s", tmp->key);
		if (tmp->value)
			printf("=\"%s\"\n", tmp->value);
		else
			printf("\n");
		lst = lst->next;
	}
}
