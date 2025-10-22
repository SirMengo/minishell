/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:46:42 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/22 11:52:32 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

t_envar *init_envar(char *key, char *value)
{
	t_envar *tmp;

	tmp = calloc(1, sizeof(t_envar));
	if (!tmp)
		return (NULL); //func para limpar tudo
	tmp->key = ft_strdup(key);
	tmp->value = ft_strdup(value);
	if (!tmp->key || !tmp->value)
	{
		free(key);
		free(value);
		return (NULL);
	}
	return (tmp);
}
