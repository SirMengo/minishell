/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:18:50 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/24 15:58:27 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

char	**lst_to_arr(t_list *lst)
{
	char	**matrix;
	int		i;

	matrix = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
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
	char	**split;
	int		i;
	t_list	*node;

	if (content[0] == '\0')
		return (1);
	split = ft_split_espace(content);
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
	return (1);
}

void	clean_cmd(t_cmd *cmd)
{
	free_arr(cmd->arg);
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	if (cmd->fd_out != 0)
		close(cmd->fd_out);
	free(cmd);
}

void	clean_cmd_arr(void)
{
	int		i;
	t_cmd	**cmd;

	cmd = data()->cmd;
	if (!cmd)
		return ;
	i = 0;
	while (cmd[i])
	{
		clean_cmd(cmd[i]);
		i++;
	}
	free(data()->cmd);
	data()->cmd = NULL;
}
