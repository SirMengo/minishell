/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:16:44 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/04 15:34:11 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

// Pode causar problema porcausa de retorno dos builtins, se eles retornarem algo sem ser 0 lixa isto tudo e nao conseguimos ver porque
int is_builtin(char **arr)
{
	if(ft_strcmp("cd", arr[0]) == 0)
		return (cd(arr), 1);
	if(ft_strcmp("echo", arr[0]) == 0)
		return (echo(arr), 1);
	if(ft_strcmp("env", arr[0]) == 0)
		return (show_envars(), 1);
	if(ft_strcmp("exit", arr[0]) == 0)
		return (ft_exit(arr), 1);
	if(ft_strcmp("export", arr[0]) == 0)
		return (export(arr), 1);
	if(ft_strcmp("pwd", arr[0]) == 0)
		return (pwd(), 1);
	if(ft_strcmp("unset", arr[0]) == 0)
		return (unset(arr), 1);
	return (0);
}
