/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:13:06 by xalves            #+#    #+#             */
/*   Updated: 2026/02/25 13:13:08 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	preparelist(void)
{
	char	**strarr_aux;
	int		i;
	int		j;
	int		start;

	i = 0;
	while (data()->manager.cmd[i])
	{
		start = i;
		j = 0;
		while (data()->manager.cmd[i] \
&& ft_strcmp("|", data()->manager.cmd[i]) != 0)
			i++;
		strarr_aux = malloc(sizeof(char *) * (i - start + 1));
		if (!strarr_aux)
			return ;
		while (start < i)
			strarr_aux[j++] = data()->manager.cmd[start++];
		strarr_aux[j] = NULL;
		ft_lstadd_back(&data()->manager.cmds, ft_lstnew(init_cmd(strarr_aux)));
		free(strarr_aux);
		if (data()->manager.cmd[i])
			i++;
	}
}
