/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:19:16 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/25 13:11:46 by xalves           ###   ########.fr       */
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
