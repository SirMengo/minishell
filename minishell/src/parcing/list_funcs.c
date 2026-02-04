/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:38:58 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/04 15:12:51 by msimoes          ###   ########.fr       */
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

t_args	*init_cmd(char **content)
{
	t_args	*aux;
	int		i;

	aux = ft_calloc(1, sizeof(t_args));
	if (!aux)
		return (NULL);
	i = 0;
	while (content[i])
		i++;
	aux->content = ft_calloc(i + 1, sizeof(char *));
	if (!aux->content)
		return (free(aux), NULL);
	i = 0;
	while (content[i])
	{
		aux->content[i] = ft_strdup(content[i]);
		if (!aux->content[i])
			return (free_arrstr(aux->content), free(aux), NULL);
		i++;
	}
	aux->content[i] = NULL;
	aux->type = loop_type(aux->content);
	if (!aux->type)
		return (free_arrstr(aux->content), free(aux), NULL);
	return (aux);
}
