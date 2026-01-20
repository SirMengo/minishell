/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:16:44 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/14 13:15:41 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

// Pode causar problema porcausa de retorno dos builtins, se eles retornarem algo sem ser 0 lixa isto tudo e nao conseguimos ver porque
int is_builtin(char *str)
{
	if(ft_strcmp("cd", str) == 1)
		return (cd(str), 1);
	if(ft_strcmp("echo", str) == 1)
		return (echo(str), 1);
	if(ft_strcmp("env", str) == 1)
		return (show_envars(), 1);
	if(ft_strcmp("exit", str) == 1)
		return (ft_exit(str), 1);
	if(ft_strcmp("export", str) == 1)
		return (export(str), 1);
	if(ft_strcmp("pwd", str) == 1)
		return (pwd(), 1);
	if(ft_strcmp("unset", str) == 1)
		return (unset(str), 1);
	return (0);
}
