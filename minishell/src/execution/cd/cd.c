/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:17:31 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/07 16:37:49 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int	update_oldpwd(t_list *lst, char *st)
{
	t_envar	*aux;
	char	cwd[PATH_MAX];

	while(lst)
	{
		aux = (t_list *)lst->content;
		if (ft_strcmp(aux->key, "OLDPWD") == 0)
		{
			getcwd(cwd, PATH_MAX);
			free(aux->value);
			aux->value = ft_strdup(cwd);
		}
		lst = lst->next;
	}
}

int	update_pwd(t_list *lst, char *st)
{
	t_envar *aux;
	char	cwd[PATH_MAX];
	
	while(lst)
	{
		aux = (t_list *)lst->content;
		if (ft_strcmp(aux->key, "PWD") == 0)
		{
			getcwd(cwd, PATH_MAX);
			free(aux->value);
			aux->value = ft_strdup(cwd);
		}
		lst = lst->next;
	}
}

int	cd(t_list *lst, char *st)
{
	t_envar *aux;
	char	cwd[PATH_MAX];

	get(cwd, PATH_MAX);
	while (lst)
	{
		if (ft_strcmp())
	}
}

int main(int ac, char **av, char **ev)
{
	t_list	*lst = NULL; 
	create_lst(&lst, ev);
	cd(lst, av[1]);
}