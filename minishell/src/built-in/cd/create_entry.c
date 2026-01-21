/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:55:12 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/20 14:36:25 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

int	create_pwd(char *cwd)
{
	t_list	*node;
	t_envar	*envar;

	envar = init_envar("PWD", cwd);
	if (envar == NULL)
		return (1);
	node = ft_lstnew(envar);
	if (node == NULL)
	{
		free(envar->key);
		free(envar->value);
		free(envar);
		return (1);
	}
	ft_lstadd_back(&data()->env, node);
	return (0);
}

int	create_opwd(char *cwd)
{
	t_list	*node;
	t_envar	*envar;

	envar = init_envar("OLDPWD", cwd);
	if (envar == NULL)
		return (1);
	node = ft_lstnew(envar);
	if (node == NULL)
	{
		free(envar->key);
		free(envar->value);
		free(envar);
		return (1);
	}
	ft_lstadd_back(&data()->env, node);
	return (0);
}

static int	change_envar(t_envar *aux, char *o_cwd, char *n_cwd)
{
	char	*new_value;

	if (ft_strcmp(aux->key, "PWD") == 0)
	{
		new_value = ft_strdup(n_cwd);
		if (new_value == NULL)
		{
			ft_printerror("cd: memory allocation failed.");
			return (1);
		}
		free(aux->value);
		aux->value = new_value;
	}
	if (ft_strcmp(aux->key, "OLDPWD") == 0)
	{
		new_value = ft_strdup(o_cwd);
		if (new_value == NULL)
		{
			ft_printerror("cd: memory allocation failed");
			return (1);
		}
		free(aux->value);
		aux->value = new_value;
	}
	return (0);
}

int	update_envar(char *o_cwd, char *n_cwd)
{
	t_envar	*aux;
	t_list	*tmp;

	tmp = data()->env;
	while (tmp)
	{
		aux = (t_envar *)tmp->content;
		if (change_envar(aux, o_cwd, n_cwd) != 0)
			return (1);
		tmp = tmp->next;
	}
	return (check_exists(o_cwd, n_cwd));
}
