/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:25:36 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/20 13:00:19 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static int	has_flag(char *str)
{
	size_t i;

	i = 1;
	if (!str || str[0] != '-')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	echo(char **av)
{
	int	flag;
	int	i;

	flag = has_flag(av[1]);
	i = 1 + flag;
	while (av[i] != NULL)
	{
		printf("%s", av[i]);
		if (av[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (flag == 0)
		printf("\n");
	cmd_error(0);
	return (0);
}
