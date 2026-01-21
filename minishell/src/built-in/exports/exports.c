/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:30:51 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/20 16:13:56 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

int	export(char **arr)
{
	int	i;
	int	result;

	if (arr == NULL)
	{
		show_envars();
		return (0);
	}
	i = 1;
	result = 0;
	while (arr[i])
	{
		if (init_export(arr[i]) != 0)
			result = 1;
		i++;
	}
	return (result);
}
