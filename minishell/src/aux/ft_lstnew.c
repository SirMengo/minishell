/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:37:32 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/13 15:28:19 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

t_envar	*ft_lstnew(char *key, char *value)
{
	t_envar	*new;

	new = malloc(sizeof(t_envar));
	if (!new)
		return (NULL);
	new->name = key;
	new->value = value;
	new->next = NULL;
	return (new);
}
