/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:30:51 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/06 14:29:00 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

int	export(char **arr)
{
	int	i;
	int	result;

	if (arr[1] == NULL)
	{
		show_export();
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
