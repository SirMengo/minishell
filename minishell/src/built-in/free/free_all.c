/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:19:16 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/16 14:56:51 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

void	free_lists(t_list *lst)
{
	t_envar	*aux;
	
	while (lst)
	{
		aux = lst->content;
		if (aux->key)
			free(aux->key);
		if (aux->value)
			free(aux->value);
		lst = lst->next;	
	}
	free(lst);
	return ;
}

void	free_all(t_list *lst)
{

}