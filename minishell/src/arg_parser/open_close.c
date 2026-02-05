/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:06:23 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/05 19:36:10 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

static int	is_space(char *str)
{
	int		i;
	char	flag;

	i = 0;
	while(str[i])
	{
		if(str[i] == '"' || str[i] == '\'')
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

int open_redirect(char *name)
{
	return (open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664));
}

int open_append(char *name)
{
	return (open(name, O_WRONLY | O_CREAT | O_APPEND, 0664));
}

int	open_input(char *name)
{
	return (open(name, O_RDONLY, 0400));
}

int	open_fd(char *name, int *arg_fd, int (*func)(char *))
{
	char	*tmp;
	
	if (*arg_fd != 0)
		close(*arg_fd);
	tmp = handle_envarargs(name);
	if (!tmp)
		return (-1);
	if (is_space(tmp))
		return (ft_printerror("MiniHorse: Ambiguous redirect\n"), 0);
	removequotes(tmp);
	*arg_fd = func(tmp);
	free(tmp);
	if (*arg_fd == -1)
	{
		perror("MiniHorse:");
		if (errno != EISDIR)
			return (-1);
		return (0);
	}
	return (1);
}
