/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenschecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:32:22 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/25 12:25:29 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//----------------Tokens-----------------------

int	checktokenstr(int idx, char firstchar)
{
	if (firstchar == '|')
		if (ft_strcmp("|", data()->manager.cmd[idx]) == 0)
			return (0);
	if (firstchar == '<')
	{
		if (ft_strcmp("<", data()->manager.cmd[idx]) == 0)
			return (0);
		else if (ft_strcmp("<<", data()->manager.cmd[idx]) == 0)
			return (0);
	}
	if (firstchar == '>')
	{
		if (ft_strcmp(">", data()->manager.cmd[idx]) == 0)
			return (0);
		else if (ft_strcmp(">>", data()->manager.cmd[idx]) == 0)
			return (0);
	}
	return (ft_printerror("syntax error, unexpected token"), 1);
}

int	is_redir_error(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

// Check if redirection is followed by a valid argument
int	checkinvalidtokens(void)
{
	int		i;
	char	firstchar;

	i = 0;
	while (data()->manager.cmd[i] != NULL)
	{
		firstchar = data()->manager.cmd[i][0];
		if (firstchar == '|' || firstchar == '<' || firstchar == '>')
		{
			if (checktokenstr(i, firstchar) == 1)
				return (1);
			if (firstchar == '<' || firstchar == '>')
			{
				if (data()->manager.cmd[i + 1] == NULL)
					return (ft_printerror(\
"\nSyntax error: expected file after redirection\n"), 1);
				if (is_redir_error(data()->manager.cmd[i + 1][0]))
					return (ft_printerror(\
"\nSyntax error: unexpected token after redirection\n"), 1);
			}
		}
		i++;
	}
	return (0);
}
