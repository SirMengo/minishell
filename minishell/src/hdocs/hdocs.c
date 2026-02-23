/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdocs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:15:12 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/22 19:06:48 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdocs.h"

char	*hdoc(char *eof, bool *close_fl)
{
	char	*line;
	char	*ret;
	char	*tmp;

	*close_fl = false;
	ret = ft_strdup("");
	while (1)
	{
		line = readline(">");
		if (line == NULL)
			return (*close_fl = errno != ENOMEM, free(ret), NULL);
		if (ft_strcmp(line, eof) == 0)
		{
			free(line);
			break ;
		}
		tmp = ft_strjoin(ret, line);
		free(ret);
		free(line);
		ret = ft_strjoin(tmp, "\n");
		free(tmp);
		if (!ret)
			return (NULL);
	}
	return (ret);
}

bool	hdoc_need_expand(char *eof)
{
	if (ft_findchar(eof, '"') || ft_findchar(eof, '\''))
	{
		removequotes(eof);
		return (false);
	}
	return (true);
}

int	hdoc_main(char *eof)
{
	bool	flag;
	bool	close_fl;
	char	*hdoc_str;
	char	*str;
	int		fd[2];

	close_fl = false;
	flag = hdoc_need_expand(eof);
	hdoc_str = hdoc(eof, &close_fl);
	if (close_fl == true)
	{
		if (data()->err_code == 130)
			return (0);
		ft_printerror("Warning heredoc delimited by close flag\n");
	}
	if (flag == false)
		str = handle_envarargs(hdoc_str);
	else
		str = ft_strdup(hdoc_str);
	free (hdoc_str);
	if (!str)
		return (-1);
	if (pipe(fd) == -1)
		return (free(str), -1);
	return (ft_putstr_fd(str, fd[1]), close(fd[1]), free(str), fd[0]);
}
