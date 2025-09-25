/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:30:58 by msimoes           #+#    #+#             */
/*   Updated: 2025/09/25 11:25:22 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
//int	g_var;

void	get_argv(t_manager manager)
{
	manager.argv = ft_split(manager.input, ' ');
	manager.argc = ft_count_words(manager.input, ' ');
}

int main(int argc, char **argv, char **envp)
{
	static t_manager	manager;

	(void)argc;
	(void)argv;
	(void)envp;

	while (manager.signal != SIGINT && manager.signal != SIGQUIT)
	{
		manager.input = readline("");
		get_argv
		printf("Input -> %s\n", manager.input);
	}

}
