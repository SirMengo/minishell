/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:33:28 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/15 12:50:50 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	err_handler(char *str, int err, char *cmd)
{
	if (err == ENOMEM)
		ft_printerror("MiniHorse: %s", str);
	else
		ft_printerror("MiniHorse: %s: %s", str, cmd);
	cmd_error(err);
	return (0);
}
