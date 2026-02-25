/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:38:58 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/25 11:01:27 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

// ---------------------List Funcs--------------------------

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

int	is_redirection(char *s)
{
	if (!s)
		return (0);
	return (
		!ft_strcmp(s, ">") || \
		!ft_strcmp(s, ">>") || \
		!ft_strcmp(s, "<") || \
		!ft_strcmp(s, "<<")
	);
}

char	*get_redir_type(char *s)
{
	if (!ft_strcmp(s, ">"))
		return (ft_strdup("redirect"));
	if (!ft_strcmp(s, ">>"))
		return (ft_strdup("append"));
	if (!ft_strcmp(s, "<"))
		return (ft_strdup("input"));
	if (!ft_strcmp(s, "<<"))
		return (ft_strdup("heredoc"));
	return (ft_strdup("arg"));
}

static int	handle_token(t_args *aux, char **content, int *i, int *j)
{
	if (is_redirection(content[*i]))
	{
		if (!content[*i + 1])
			return (0);
		aux->content[*j] = ft_strdup(content[*i + 1]);
		aux->type[*j] = get_redir_type(content[*i]);
		(*j)++;
		*i += 2;
	}
	else
	{
		aux->content[*j] = ft_strdup(content[*i]);
		aux->type[*j] = ft_strdup("arg");
		(*j)++;
		(*i)++;
	}
	return (1);
}

t_args	*init_cmd(char **content)
{
	t_args	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = ft_calloc(1, sizeof(t_args));
	if (!aux)
		return (NULL);
	aux->content = ft_calloc(ft_arrlen(content) + 1, sizeof(char *));
	aux->type = ft_calloc(ft_arrlen(content) + 1, sizeof(char *));
	if (!aux->content || !aux->type)
		return (free(aux), NULL);
	while (content[i])
	{
		if (!handle_token(aux, content, &i, &j))
			return (NULL);
	}
	aux->content[j] = NULL;
	aux->type[j] = NULL;
	return (aux);
}
