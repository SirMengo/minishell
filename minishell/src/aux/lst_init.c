/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:46:42 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/05 12:37:35 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

t_envar *init_envar(char *key, char *value)
{
	t_envar *envar;

	envar = calloc(1, sizeof(t_envar));
	if (!envar)
		return (NULL); //func para limpar tudo
	envar->key = ft_strdup(key);
	if (!envar->key)
	{
		free(envar);
		return (NULL);
	}
	if (value != NULL)
		envar->value = ft_strdup(value);
	else
		envar->value = NULL;
	return (envar);
}
