/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:11:11 by xalves            #+#    #+#             */
/*   Updated: 2026/02/25 13:11:18 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

static int	is_space(char *str)
{
	int		i;
	char	flag;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			flag = str[i];
			i++;
			while (str[i] != flag)
				i++;
			flag = '\0';
		}
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	open_redirect(char *name)
{
	if (access(name, F_OK) == 0 && access(name, W_OK) != 0)
		return (0);
	return (open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664));
}

int	open_append(char *name)
{
	if (access(name, F_OK) == 0 && access(name, W_OK) != 0)
		return (0);
	return (open(name, O_WRONLY | O_CREAT | O_APPEND, 0664));
}

int	open_input(char *name)
{
	if (access(name, R_OK) != 0)
		return (0);
	return (open(name, O_RDONLY, 0400));
}

int	open_fd(char *name, int *arg_fd, int (*func)(char *))
{
	if (*arg_fd != 0)
		close(*arg_fd);
	if (is_space(name))
		return (ft_printerror("MiniHorse: Ambiguous redirect\n"), -1);
	removequotes(name);
	*arg_fd = func(name);
	if (*arg_fd <= 0)
	{
		ft_printerror("MiniHorse: %s: ", name);
		perror(NULL);
		cmd_error(1);
		if (errno == EISDIR || *arg_fd == 0)
			return (-1);
		return (-2);
	}
	return (1);
}
