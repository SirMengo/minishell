/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdocs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:15:12 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/19 10:57:19 by msimoes          ###   ########.fr       */
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
	if (!ret)
		return (NULL);
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
	int		fd[2];

	flag = false;
	if (ft_findchar(eof, '"') || ft_findchar(eof, '\''))
	{
		flag = true;
		removequotes(eof);
	}
	hdoc_str = hdoc(eof, &close_fl);
	if (close_fl == true)
		return (-1); //EOF, manter proigrama "Warning heredoc delimited by close flag"
	//Receber da func de expansao do Xavier, posto no hdoc string
	if (pipe(fd) == -1)
		return (free(hdoc_str), -2); //Erro de pipe, fechar programa 
	ft_putstr_fd(hdoc_str, fd[1]);
	close(fd[1]);
	free(hdoc_str);
	return (fd[0]);
}
