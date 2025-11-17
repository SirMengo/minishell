/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:30:51 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/14 13:33:26 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int export(t_list **lst, char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		show_envars(lst);
	while (arr[i])
	{
		return (init_export(lst, arr[i]));
		i++;
	}
	return (0);
}
