/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:28 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/27 15:40:58 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	ft_free(t_list *lst ,char *key, char *value)
{
	t_list	*tmp;
	t_envar	*envar;

	if (key)
		free(key);
	if (value)
		free(value);
	while(lst)
	{
		tmp = lst->next;
		envar = (t_envar *)lst->content;
		if (envar)
		{
			if (envar->key)
				free(envar->key);
			if (envar->value)
				free(envar->value);
			free(envar);
		}
		free(lst);
		lst = tmp;
	}
	exit(1);
}

void	append_export(t_list *lst, char *str)
{
	char *key;
	char *value;
	char *tmp;
	int key_len;
	t_envar *aux;

	key_len = find_key(str);
	key = ft_substr(str, 0, key_len);
	value = ft_substr(str, key_len + 1, find_value(str, key_len) - key_len - 1);
	if (!key || !value)
		ft_free(lst, key, value);
	while (lst)
	{
		aux = (t_envar *)lst->content;
		if (ft_strcmp(aux->key, key) == 0)
		{
			if (!(tmp = ft_strjoin(aux->value, value)))
				ft_free(lst, key, value);
			free(aux->value);
			aux->value = tmp;
		}
		lst = lst->next;
	}
	free(key);
	free(value);
}

void	add_export(t_list **lst, char *str)
{
	char	*key;
	char	*value;
	int		lkey;
	t_list *node;

	lkey = find_key(str);
	key = ft_substr(str, 0, find_key(str));
	if (!key)
		fatal_error("ERROR: Failed to allocate", *lst, key, NULL);
	value = ft_substr(str, lkey + 1, find_value(str, lkey) - lkey - 1);
	if (!value)
		fatal_error("ERROR: Failed to allocate", *lst, key, value);
	node = ft_lstnew(init_envar(key, value));
	ft_lstadd_back(lst, node);
	free(key);
	free(value);
}

void	show_export(t_list *lst)
{
	t_envar	*tmp;

	while (lst)
	{
		tmp = (t_envar *)lst->content;
		printf("declare -x %s=", tmp->key);
		printf("\"%s\"",tmp->value);
		printf("\n");
		lst = lst->next;
	}
}

void	export(t_list **lst, char **ev, char *st)
{
	int i;

	i = 0;
	if(ft_isalpha(st[0]) == 0 && st[0] != '_')
		ft_printerror("bash: export: `%s': not a valid identifier", st);
	while (st[i] != '=' || st[i] != '+' || st[i] != NULL)
	{
		if (ft_isalnum(st[i]) == 0 && st[i] != '_')
		{
			ft_printerror("bash: export: `%s': not a valid identifier", st);
			break ;
		}
		i++;
	}
	i = 0;
	while (st[i] != '+' || st[i] != '=' || st[i] != NULL)
	{
		if (st[i] == '+' && st[i + 1] == '=')
			append_export(lst, st);
		else if (st[i] == '=')
			add_export(&lst, st);
		else
			ft_printerror("bash: export: `%s': not a valid identifier", st);
		i++;
	}
}

int main(int ac, char **av, char **ev)
{
	t_list *lst = NULL;
	char str[100] = "AAA=BBB";

	create_lst(&lst, ev);
	add_export(&lst, str);
	show_export(lst);
	append_export(lst, str);
	show_export(lst);
}