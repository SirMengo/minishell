/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:30:51 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/19 15:04:15 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int export(t_list **lst, char **arr)
{
	int	i;
	int result;

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
