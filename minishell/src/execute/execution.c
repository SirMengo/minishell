/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:01:01 by msimoes           #+#    #+#             */
/*   Updated: 2025/09/25 11:47:46 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	cmd_exec(char *argv, char **envp)
{
	char *path;
	char **cmd;

	cmd = ft_split(argv, ' ');
}