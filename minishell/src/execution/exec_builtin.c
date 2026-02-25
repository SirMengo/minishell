/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:16:44 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/25 12:59:23 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	is_builtin(char **arr)
{
	if (ft_strcmp("cd", arr[0]) == 0)
		return (cd(arr), 1);
	if (ft_strcmp("echo", arr[0]) == 0)
		return (echo(arr), 1);
	if (ft_strcmp("env", arr[0]) == 0)
		return (show_envars(), 1);
	if (ft_strcmp("exit", arr[0]) == 0)
		return (ft_exit(arr), 1);
	if (ft_strcmp("export", arr[0]) == 0)
		return (export(arr), 1);
	if (ft_strcmp("pwd", arr[0]) == 0)
		return (pwd(), 1);
	if (ft_strcmp("unset", arr[0]) == 0)
		return (unset(arr), 1);
	return (0);
}
