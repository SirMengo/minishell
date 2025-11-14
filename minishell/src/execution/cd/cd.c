/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:17:31 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/13 14:41:55 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int update_env(t_list *lst, char *str)
{
	t_envar *aux;
	char	tmp[PATH_MAX];

	getcwd(tmp, PATH_MAX);
	if (chdir(str) == 0)
	{
		while(lst)
		{
			aux = (t_envar *)lst->content;
			if (ft_strcmp(aux->key, "PWD") == 1)
				aux->key = str;
			if (ft_strcmp(aux->key, "OLDPWD") == 1)
				aux->key = ft_strdup(tmp);
			lst = lst->next;
		}
	}
}

int main(int ac, char **av, char **ev)
{
	t_list	*lst = NULL; 
	create_lst(&lst, ev);
	cd(lst, av[1]);
}