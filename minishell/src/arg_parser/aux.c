/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:18:50 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/06 16:09:42 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

char	**lst_to_arr(t_list *lst)
{
	char	**matrix;
	int		i;
	
	matrix = ft_calloc(ft_lstsize(lst) + 1, sizeof(char*));
	if (!matrix)
	return (NULL);
	i = 0;
	while (lst)
	{
		matrix[i] = ft_strdup(lst->content);
		if (matrix[i] == NULL)
			return (free_arr(matrix), NULL);
		lst = lst->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int	add_to_list(char *content, t_list **lst)
{
	char	*tmp;
	char	**split;
	int		i;
	t_list	*node;
	
	tmp = handle_envarargs(content);
	split = ft_split_espace(tmp);
	free(tmp);
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		removequotes(split[i]);
		node = ft_lstnew(split[i]);
		if (!node)
			return (free_arr(split), 0);
		ft_lstadd_back(lst, node);
		i++;
	}
	free(split);
	free(content);
	return (1);
}

void	clean_cmd(t_cmd *cmd)
{
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	if (cmd->fd_out != 0)
		close(cmd->fd_out);
}

void	clean_cmd_arr(t_cmd **cmd)
{
	int	i;

	i = 0;
	while(cmd[i])
	{
		clean_cmd(cmd[i]);
		i++;
	}
	free(cmd);
}
