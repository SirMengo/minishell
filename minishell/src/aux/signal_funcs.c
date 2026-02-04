/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:01:59 by xalves            #+#    #+#             */
/*   Updated: 2026/02/04 12:12:01 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

volatile sig_atomic_t	g_signal_flag = 0;

/// @brief tells readline to stop, move to a new line, and show the prompt again
/// @param sig signal detected
/// @param info not used
/// @param context not used
void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGINT)
	{
		g_signal_flag = SIGINT;
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

//first block is for to handle SIGINT (Ctr + C)
//	(44)signal.sa_sigaction = handle_signal;
//second block is for to handle ignores SIGQUIT
//	(48)ignore_quit.sa_handler = SIG_IGN;
void	setup_signals(void)
{
	struct sigaction	signal;
	struct sigaction	ignore_quit;

	signal.sa_sigaction = handle_signal;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &signal, NULL);
	ignore_quit.sa_handler = SIG_IGN;
	sigemptyset(&ignore_quit.sa_mask);
	ignore_quit.sa_flags = 0;
	sigaction(SIGQUIT, &ignore_quit, NULL);
}

//first if is for (Ctrl-D)
//second if is for (Ctrl-C)
int	checkforsignals()
{
	if (data()->manager.input == NULL)
	{
		printf("Ctrl-D pressed\n");
		rl_clear_history();
		return (1);
	}
	if (g_signal_flag == SIGINT)
	{
		free(data()->manager.input);
		data()->manager.input = NULL;
		g_signal_flag = 0;
		return (2);
	}
	return (0);
}
