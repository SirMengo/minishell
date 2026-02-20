/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:30:51 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/20 10:42:44 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

int	export(char **arr)
{
	int	i;
	int	err;
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
		err = init_export(arr[i]);
		if (err != 0)
		{
			cmd_error(err);
			result = 1;
		}
		i++;
	}
	return (result);
}
