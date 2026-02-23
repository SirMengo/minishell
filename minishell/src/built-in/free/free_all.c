/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:19:16 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/22 18:04:41 by vampaier2        ###   ########.fr       */
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
