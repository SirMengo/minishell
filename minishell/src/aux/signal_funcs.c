/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:01:59 by xalves            #+#    #+#             */
/*   Updated: 2025/10/21 11:35:37 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "aux.h"

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

void	setup_signals(void)
{
	struct sigaction signal;
	struct sigaction ignore_quit;

	// handles SIGINT Ctr + C
	signal.sa_sigaction = handle_signal;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &signal, NULL);

	// ignores SIGQUIT
	ignore_quit.sa_handler = SIG_IGN;
	sigemptyset(&ignore_quit.sa_mask);
	ignore_quit.sa_flags = 0;
	sigaction(SIGQUIT, &ignore_quit, NULL);
}

int	checkforsignals(t_manager *manager)
{
	if (manager->input == NULL) // Ctrl-D
	{
		printf("Ctrl-D pressed\n");
		rl_clear_history();
		return 1;
	}
	if (g_signal_flag == SIGINT) // Ctrl-C
	{
		free(manager->input);
		manager->input = NULL;
		g_signal_flag = 0;
		return 2;
	}
	return 0;
}