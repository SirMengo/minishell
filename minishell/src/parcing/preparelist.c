/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:56:02 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/19 15:24:15 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	preparelist(t_manager *manager)
{
	char	**strarr_aux;
	int		i;
	int		j;
	int		start;

	i = 0;
	while (manager->cmd[i])//em teoria funciona
	{
		start = i;
		j = 0;
		while (manager->cmd[i] && ft_strcmp("|", manager->cmd[i]) != 0)
			i++;
		strarr_aux = malloc(sizeof(char *) * (i - start + 1));
		if (!strarr_aux)
			return ;
		while (start < i)
			strarr_aux[j++] = manager->cmd[start++];
		strarr_aux[j] = NULL;
		ft_lstadd_back(&manager->cmds, ft_lstnew(init_cmd(strarr_aux)));
		free(strarr_aux);
		if (manager->cmd[i])
			i++; // skip '|'
	}
}

