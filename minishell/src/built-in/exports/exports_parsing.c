/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:48:40 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/05 14:34:08 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static int	append_parser(char *st)
{
	t_envar	*aux;
	t_list	*current;
	char	*key;
	char	*value;

	key = find_key(st);
	value = find_value(st);
	if (!key)
		return (free_key_value(key, value), 1);
	current = data()->env;
	while (current)
	{
		aux = (t_envar *)current->content;
		if (ft_strcmp(key, aux->key) == 0)
		{
			if (value == NULL || value[0] == '\0')
				return (free_key_value(key, value), 0);
			else
				return (append_export(key, value));
		}
		current = current->next;
	}
	return (add_export(key, value));
}

static int	no_sign_parser(char *st)
{
	t_envar	*aux;
	t_list	*current;
	char	*key_copy;

	current = data()->env;
	while (current)
	{
		aux = (t_envar *)current->content;
		if (ft_strcmp(st, aux->key) == 0)
			return (0);
		current = current->next;
	}
	key_copy = ft_strdup(st);
	if (!key_copy)
		return (1);
	return (add_export(key_copy, NULL));
}

int	init_export(char *st)
{
	char		*key;
	int			i;
	static char	err1[10] = "export: `";
	static char	err2[26] = "': not a valid identifier";

	i = 1;
	key = find_key(st);
	if (!key)
		return (1);
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (ft_printerror("%s%s%s", err1, key, err2), free(key), 1);
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (ft_printerror("%s%s%s", err1, key, err2), free(key), 1);
		i++;
	}
	free(key);
	if (ft_findchar(st, '=') == 0)
		return (no_sign_parser(st));
	if (is_append(st) == 1)
		return (append_parser(st));
	return (add_parser(st));
}
