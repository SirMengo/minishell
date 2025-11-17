/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:17:31 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/17 14:29:58 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int	update_envar(t_list *lst, char *o_cwd, char *n_cwd)
{
	t_envar *aux;

	while(lst)
	{
		aux = (t_envar *)lst->content;
		if (ft_strcmp(aux->key, "PWD") == 0)
		{
			free(aux->value);
			aux->value = ft_strdup(n_cwd);
		}
		if (ft_strcmp(aux->key, "OLDPWD") == 0)
		{
			free(aux->value);
			aux->value = ft_strdup(o_cwd);
		}
		lst = lst->next;
	}
}

int cd(t_list *lst, char *str)
{
	t_envar *aux;
	char	tmp[PATH_MAX];
	char	n_cwd[PATH_MAX];

	getcwd(tmp, PATH_MAX);
	if (chdir(str) == 0)
	{
		getcwd(n_cwd, PATH_MAX);
		update_envar(lst, tmp, n_cwd);
	}
	else
		printf("cd: no such file in directory: %s", str);
}
