/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:17:31 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/18 14:10:52 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int	check_exists(t_list **lst, char *o_cwd, char *n_cwd)
{
	t_envar	*aux;
	t_list	*tmp;
	int		pwd;
	int		oldpwd;

	pwd = 0;
	oldpwd = 0;
	tmp = *lst;
	while (tmp)
	{
		aux = (t_envar *)tmp->content;
		if (ft_strcmp(aux->key, "PWD") == 0)
			pwd = 1;
		if (ft_strcmp(aux->key, "OLDPWD") == 0)
			oldpwd = 1;
		tmp = tmp->next;
	}
	if (pwd == 0)
		ft_lstadd_back(lst, ft_lstnew(init_envar("PWD", n_cwd)));
	if (oldpwd == 0)
		ft_lstadd_back(lst, ft_lstnew(init_envar("OLDPWD", o_cwd)));
}

int	update_envar(t_list **lst, char *o_cwd, char *n_cwd)
{
	t_envar *aux;
	t_list	*tmp;

	tmp = *lst;
	while(tmp)
	{
		aux = (t_envar *)tmp->content;
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
		tmp = tmp->next;
	}
	check_exists(lst, o_cwd, n_cwd);
}

int	cd_home(t_list **lst)
{
	t_envar	*aux;
	t_list	*tmp;
	char	cwd[PATH_MAX];

	getcwd(cwd, PATH_MAX);
	tmp = *lst;
	while(tmp)
	{
		aux = (t_envar *)tmp->content;
		if (ft_strcmp(aux->key, "HOME") == 0)
			if (chdir(aux->value) == -1)
				return (perror("Error: "), 1);
			else
				return (update_envar(lst, cwd, aux->value), 0);
			tmp = tmp->next;
		}
	return (1); 
}

int cd(t_list **lst, char *str)
{
	t_envar *aux;
	char	tmp[PATH_MAX];
	char	n_cwd[PATH_MAX];

	getcwd(tmp, PATH_MAX);
	if (str == NULL)
	{
		cd_home(lst);
		return (0);
	}
	if (chdir(str) == 0)
	{
		getcwd(n_cwd, PATH_MAX);
		update_envar(lst, tmp, n_cwd);
	}
	else
		perror("cd");
	return (0);
}
