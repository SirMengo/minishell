/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:37:43 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/23 14:24:28 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	cmd_error(int code)
{
	data()->err_code = code;
}

void	cmd_success(void)
{
	data()->err_code = 0;
}
