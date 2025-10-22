/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:15:20 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/22 10:21:51 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	unset(t_envar *lst, char *str)
{
	t_envar node;
	int lkey;
	char *key;

	lkey = find_key(str);
	key = ft_substr(str, 0, lkey);
	while(lst)
	{
		if(ft_strcmp(key, lst->key) != 0)
		{
			//da clear a node
		}
		lst = lst->next;
	}
	free(key);
}
