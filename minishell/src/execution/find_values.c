/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:35:00 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/23 15:05:33 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	find_key(char *envars)
{
	int	i;

	i = 0;
	while (envars[i] != '=' && envars[i] != '\0')
		i++;
	return (i);
}

int	find_value(char *envars, int key_end)
{
	while (envars[key_end] != '\0')
		key_end++;
	return (key_end);
}

