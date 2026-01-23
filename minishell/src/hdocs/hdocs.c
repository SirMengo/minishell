/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdocs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:15:12 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/23 11:51:28 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdocs.h"

char	*hdoc(char *eof, bool *close_fl)
{
	char	*line;
	char	*ret;
	char	*tmp;

	*close_fl = false;
	ret = NULL;
	while(1)
	{
		line = readline('>');
		if (line == NULL)
			return (*close_fl = errno != ENOMEM, free(ret), NULL);
		if (ft_strcmp(line, eof) == 0)
			break ;
		tmp = ft_strjoin(line, ret);
		free(ret);
		free(line);
		if (!tmp)
			return (free(line), NULL);
		ret = tmp;
	}
	return (ret);
}

int	hdoc_main(char *eof)
{
	bool	flag;
	bool	close_fl;
	char	*hdoc_str;
	char	*str;
	int		fd[2];

	flag = false;
	if (ft_findchar(eof, '"') || ft_findchar(eof, '\''))
	{
		flag = true;
		removequotes(eof);
	}
	hdoc_str = hdoc(eof, &close_fl);
	if (close_fl == true)
		ft_printerror("Warning heredoc delimited by close flag\n");
	str = handle_envarargs(hdoc_str);
	free (hdoc_str);
	if (!str)
		return (-1);
	if (pipe(fd) == -1)
		return (free(str), -1); //Erro de pipe, fechar programa 
	ft_putstr_fd(str, fd[1]);
	close(fd[1]);
	free(str);
	return (fd[0]);
}
