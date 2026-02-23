/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:38:58 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/22 17:51:01 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

// ---------------------List Funcs--------------------------

char	*detect_type(char *content)
{
	if (ft_strcmp("|", content) == 0)
		return (ft_strdup("pipe"));
	if (ft_strcmp(">", content) == 0)
		return (ft_strdup("redirect"));
	if (ft_strcmp(">>", content) == 0)
		return (ft_strdup("append"));
	if (ft_strcmp("<", content) == 0)
		return (ft_strdup("input"));
	if (ft_strcmp("<<", content) == 0)
		return (ft_strdup("heredoc"));
	return (ft_strdup("arg"));
}

char	**loop_type(char **content)
{
	char	**typearr;
	int		i;

	i = 0;
	while (content[i])
		i++;
	typearr = ft_calloc(i + 1, sizeof(char *));
	if (!typearr)
		return (NULL);
	i = 0;
	while (content[i])
	{
		typearr[i] = detect_type(content[i]);
		if (!typearr[i])
			return (free_arrstr(typearr), NULL);
		i++;
	}
	typearr[i] = NULL;
	return (typearr);
}

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

//	ARG,
//	REDIR_IN,		// <
//	REDIR_OUT,		// >
//	REDIR_APPEND,	// >>
//	HEREDOC			// <<
typedef enum e_type
{
	ARG,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC
}	t_type;

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
		if (is_redirection(content[i]))
		{
			if (!content[i + 1])
				return (NULL);
			aux->content[j] = ft_strdup(content[i + 1]);
			aux->type[j] = get_redir_type(content[i]);
			j++;
			i += 2;
		}
		else
		{
			aux->content[j] = ft_strdup(content[i]);
			aux->type[j] = ft_strdup("arg");
			j++;
			i++;
		}
	}
	aux->content[j] = NULL;
	aux->type[j] = NULL;
	return (aux);
}
