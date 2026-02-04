/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:33:28 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/04 14:28:48 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	err_handler(char *str, int err, char *cmd)
{
	if (err == ENOMEM || cmd == NULL)
		ft_printerror("MiniHorse: %s\n", str);
	else
		ft_printerror("MiniHorse: %s: %s\n", cmd, str);
	cmd_error(err);
	return (0);
}
