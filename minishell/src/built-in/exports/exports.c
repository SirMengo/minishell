/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:30:51 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/06 11:47:55 by msimoes          ###   ########.fr       */
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
	i = 0;
	result = 0;
	while (arr[i])
	{
		if (init_export(arr[i]) != 0)
			result = 1;
		i++;
	}
	return (result);
}

int main(int ac, char **av, char **ev)
{
	create_lst(ev);

	export(av);
}