/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:10:40 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/17 14:09:35 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

void sh_lvl(void)
{
	t_list *tmp;
	t_envar *aux;
	char	*o_value;
	char	*n_value;
	
	tmp = data()->env; 
	while(tmp)
	{
		aux = (t_envar *)tmp->content;
		if(ft_strcmp(aux->key, "SHLVL") == 0)
		{
			o_value = aux->value;
			n_value = ft_itoa(ft_atoi(aux->value) + 1);
			aux->value = n_value;
			free(o_value);
			return ;
		}
		tmp = tmp->next;
	}
	return ;
}

int	add_env_var(char *key, char *value)
{
	t_envar *envar;
	t_list  *node;

	envar = init_envar(key, value);
	if (!envar)
		return (0);
	node = ft_lstnew(envar);
	if (!node)
	{
		free_envar(envar);
		ft_printerror("ERROR: Failed to allocate\n");
		return (0);
	}
	ft_lstadd_back(&data()->env, node);
	return (1);
}

void	init_env(char **ev)
{
	char	cwd[PATH_MAX];

	if (ev[0] == NULL)
	{
		if (!getcwd(cwd, PATH_MAX))
			cwd[0] = '\0';
		add_env_var("PWD", cwd);
		add_env_var("SHLVL", "1");
		add_env_var("_", "/usr/bin/env");
	}
	else
	{
		create_lst(ev);
		sh_lvl();
	}
}
