/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envars.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:11:19 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/13 14:50:15 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	count_envars(char **envars)
{
	int	i;

	i = 0;
	while (envars[i])
		i++;
	return (i);
}

void	create_lst(t_envar **lst ,char **envars)
{
	int	i;
	t_envar *node;
	
	i = 0;
	while (envars[i])
	{
		node = ft_lstnew(envars[i]);
		ft_lstadd_back(lst, node);
		i++;
	}
}