/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:09:23 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/06 13:30:00 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

static int	check_hdoc(t_args *content)
{
	int	fd;
	int	i;

	fd = 0;
	i = 0;
	while (content->type[i] != NULL)
	{
		if (!ft_strcmp(content->type[i], "heredoc"))
		{
			if (fd != 0)
				close(fd);
			fd = hdoc_main(content->content[i]);
			if (fd == -1)
				return (-1);
		}
		else if (!ft_strcmp(content->type[i], "input") && fd != 0)
		{
			close (fd);
			fd = 0;
		}
		i++;
	}
	return (fd);
}

static int check_redir(t_args *content, t_cmd *cmd)
{
	int	i;
	int	open_res;
	int	last_infd;

	i = 0;
	last_infd = 0;
	open_res = 0;
	while (content->type[i] != NULL)
	{
		if (!ft_strcmp(content->type[i] , "redirect"))
			open_res = open_fd(content->content[i], &cmd->fd_out, open_redirect);
		else if (!ft_strcmp(content->type[i] , "append"))
			open_res = open_fd(content->content[i], &cmd->fd_out, open_append);
		else if (!ft_strcmp(content->type[i] , "input"))
			open_res = open_fd(content->content[i], &last_infd, open_input);
		if (open_res <= -1)
			return (open_res);
		i++;
	}
	if (cmd->fd_in == 0)
		cmd->fd_in = last_infd;
	else if (last_infd != 0)
		close (last_infd);
	return (1);
}

static int	check_arg(t_args *content, t_cmd *cmd)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = NULL;
	while(content->type[i])
	{
		if(!ft_strcmp(content->type[i], "arg"))
			if (!add_to_list(content->content[i], &lst))
				return (ft_lstclear(&lst, free), 0);
		i++;
	}
	cmd->arg = lst_to_arr(lst);
	return (ft_lstclear(&lst, free), 1);
}

static t_cmd	*create_cmd(t_args *content)
{
	t_cmd	*ret;
	int		code;
	
	ret = ft_calloc(1, sizeof(t_cmd));
	if (!ret)
		return (NULL);
	if (!check_arg(content, ret))
		return (clean_cmd(ret), NULL);
	ret->fd_in = check_hdoc(content);
	if (ret->fd_in == -1)
		return (clean_cmd(ret), NULL);
	code = check_redir(content, ret);
	if (code == 1)
		ret->execute = 1;
	else if (code == -2)
		return (clean_cmd(ret), NULL);
	return (ret);
}

t_cmd	**init_arg()
{
	t_cmd	**cmd;
	t_list	*tmp;
	int		i;
	
	tmp = data()->manager.cmds;
	cmd = ft_calloc(ft_lstsize(tmp) + 1, sizeof(t_cmd*));
	if (!cmd)
		return (NULL);
	i = 0;
	while (tmp)
	{
		cmd[i] = create_cmd(tmp->content);
		if (!cmd[i])
		{
			i--;
			while(i >= 0)
			{
				clean_cmd(cmd[i]);
				i--;
			}
			return (free(cmd), NULL);
		}
		tmp = tmp->next;
		i++;
	}
	return (cmd);
}
