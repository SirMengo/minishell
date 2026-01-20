/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:38:58 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/20 11:02:41 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

// ---------------------List Funcs--------------------------

char	*detect_cmd(char *content)
{
	if (ft_strcmp("echo", content) == 0)
		return (ft_strdup("echo"));
	if (ft_strcmp("cd", content) == 0)
		return (ft_strdup("cd"));
	if (ft_strcmp("pwd", content) == 0)
		return (ft_strdup("pwd"));
	if (ft_strcmp("export", content) == 0)
		return (ft_strdup("export"));
	if (ft_strcmp("unset", content) == 0)
		return (ft_strdup("unset"));
	if (ft_strcmp("env", content) == 0)
		return (ft_strdup("env"));
	if (ft_strcmp("exit", content) == 0)
		return (ft_strdup("exit"));
	return (ft_strdup("nocmd"));
}


char	*detect_type(char *content)
{
	char	*checkreturn;

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
	checkreturn = detect_cmd(content);
	if (!checkreturn)
		return (NULL);
	if (ft_strcmp("nocmd", checkreturn) != 0)
		return (checkreturn);
	free(checkreturn);
	return (ft_strdup("arg"));
}


char	**loop_type(char **content)
{
	char	**typearr;
	int		i;

	i = 0;
	while (content[i])
		i++;
	/* allocate array (+1 for NULL) */
	typearr = ft_calloc(i + 1, sizeof(char *));
	if (!typearr)
		return (NULL);
	/* fill array */
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

	/* duplicate content array */
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

	/* build type array */
	aux->type = loop_type(aux->content);
	if (!aux->type)
		return (free_arrstr(aux->content), free(aux), NULL);

	return (aux);
}


/* t_args *init_cmdsssssss(char **content)
{
	t_args *aux;

	aux = ft_calloc(1, sizeof(t_args));
	if (!aux)
		return (NULL);
	while(content[i] != NULL)
	{
		aux->content[i] = ft_strdup(content[i]); 
		i++;
	}
	if (!aux->content)
		return (free(aux), NULL);
	aux->type = detect_type(content);
	return (aux);
} */
