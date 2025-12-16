/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:19:55 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/16 14:56:24 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static	int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[1] == '\0')
			return (0);
		i = 1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static	int	is_overflow(char *str, long long *out)
{
	int	sign;
	int	i;
	int	num;

	sign = 1;
	*out = 0;
	if (!is_numeric(str))
		return (ft_printerror("exit\n"), 0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i = 1;
	}
	while (str[i])
	{
		num = str[i++] - '0';
		if (sign == 1 && *out > (LLONG_MAX - num) / 10)
			return (ft_printerror("exit\n"), 0);
		if (sign == -1 && *out < (LLONG_MIN + num) / 10)
			return (ft_printerror("exit\n"), 0);
		*out = *out * 10 + num;
	}
	*out *= sign;
	return (1);
}

int	ft_exit(char **av)
{
	int			i;
	long long	exit_value;

	i = 0;	
	while (av[i])
		i++;
	if (i > 2)
		return (ft_printerror("exit\nexit: too many arguments"), 1);
	if (i == 1)
	{
		if (is_overflow(av[1], &exit_value) == 0)
		{
			ft_printerror("exit: %s: numeric argument required", av[1]);
			return (1);
		}
	}
	//fre_all();
	exit (0);
}
