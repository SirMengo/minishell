/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:46:42 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/20 15:14:41 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

t_envar	*init_envar(char *key, char *value)
{
	t_envar	*envar;

	envar = calloc(1, sizeof(t_envar));
	if (!envar)
		return (NULL);
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
