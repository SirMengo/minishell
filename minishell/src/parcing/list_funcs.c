/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:38:58 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/07 15:14:05 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

// ---------------------List Funcs--------------------------

char *detect_cmd(char *content)
{
	if(ft_strcmp("echo", content) == 0)
		return ("echo");
	if(ft_strcmp("cd", content) == 0)
		return ("cd");
    if(ft_strcmp("pwd", content) == 0)
		return ("pwd");
	if(ft_strcmp("export", content) == 0)
		return ("export");
    if(ft_strcmp("unset", content) == 0)
		return ("unset");
	if(ft_strcmp("env", content) == 0)
		return ("env");
    if(ft_strcmp("exit", content) == 0)
		return ("exit");
	return ("nocmd");
}

char *detect_type(char *content)
{
	char	*checkreturn;
	
	if(ft_strcmp("|", content) == 0)
		return ("pipe");
	if(ft_strcmp(">", content) == 0)
		return ("redirect");
    if(ft_strcmp(">>", content) == 0)
		return ("append");
	if(ft_strcmp("<", content) == 0)
		return ("input");
    if(ft_strcmp("<<", content) == 0)
		return ("heredoc");
	checkreturn = detect_cmd(content);
	if(ft_strcmp("nocmd", checkreturn) != 0)
		return (checkreturn);
	return ("arg");
}

t_args *init_cmd(char *content)
{
	t_args *aux;

	aux = ft_calloc(1, sizeof(t_args));
	if (!aux)
		return (NULL);
	aux->content = ft_strdup(content); 
	if (!aux->content)
		return (free(aux), NULL);
	aux->type = detect_type(content);
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
