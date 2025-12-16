/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:30:51 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/16 14:56:42 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

int	export(t_list **lst, char **arr)
{
	int	i;
	int	result;

	if (arr == NULL)
	{
		show_envars(*lst);
		return (0);
	}
	i = 0;
	result = 0;
	while (arr[i])
	{
		if (init_export(lst, arr[i]) != 0)
			result = 1;
		i++;
	}
	return (result);
}
