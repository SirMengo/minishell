/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:55:12 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/18 15:09:30 by msimoes          ###   ########.fr       */
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
