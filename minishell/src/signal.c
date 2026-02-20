/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:01:59 by xalves            #+#    #+#             */
/*   Updated: 2026/02/20 14:49:52 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	sigint_default(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	if (!data()->in_child)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	cmd_error(130);
}

static void sigint_hdoc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	cmd_error(130);
	data()->stop_exec = true;
	data()->hdoc_res = dup(STDIN_FILENO);
	close(STDIN_FILENO);
}

static void kill_childs(int sig)
{
	(void)sig;
	exit_free(data()->err_code);
}

void setup_signals(void)
{
	data()->sig_int_default.sa_handler = sigint_default;
	data()->sig_int_hdoc.sa_handler = sigint_hdoc;
	data()->sig_kill.sa_handler = kill_childs;
	data()->sig_ign.sa_handler = SIG_IGN;
	sigemptyset(&data()->sig_int_default.sa_mask);
	sigemptyset(&data()->sig_int_hdoc.sa_mask);
	sigemptyset(&data()->sig_kill.sa_mask);
	sigemptyset(&data()->sig_ign.sa_mask);
	data()->sig_int_default.sa_flags = SA_RESTART;
	data()->sig_int_hdoc.sa_flags = SA_RESTART;
	data()->sig_kill.sa_flags = SA_RESTART;
	data()->sig_ign.sa_flags = SA_RESTART;
	sigaction(SIGINT, &data()->sig_int_default, NULL);
	sigaction(SIGQUIT, &data()->sig_ign, NULL);
}
