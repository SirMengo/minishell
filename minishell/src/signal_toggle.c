/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_toggle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:55:36 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/22 16:43:36 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	toggle_sig_quit(void)
{
	sigaction(SIGQUIT, &data()->sig_kill, NULL);
}

void	toggle_sig_int_hdoc(bool hdoc)
{
	if (hdoc)
		sigaction(SIGINT, &data()->sig_int_hdoc, NULL);
	else
		sigaction(SIGINT, &data()->sig_int_default, NULL);
}

int	hdoc_restore_stdin(void)
{
	bool	ret;

	ret = dup2(data()->hdoc_res, STDIN_FILENO) != -1;
	close(data()->hdoc_res);
	data()->hdoc_res = -1;
	if (!ret)
		return (-1);
	return (0);
}
