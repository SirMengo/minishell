/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:12:28 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/05 13:10:36 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int	ft_free(t_list *lst ,char *key, char *value)
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

void	append_export(t_list *lst, char *key, char *value)
{
	t_envar *aux;
	char	*temp;

	while(lst)
	{
		aux = (t_envar *)lst->content; 
		if (ft_strcmp(aux->key, key) == 0)
		{
			temp = aux->value;
			aux->value = ft_strjoin(temp, value);
			free(temp);
			free(key);
			free(value);
			return ;
		}
		lst = lst->next;
	}
	free(key);
	free(value);
}

void	add_export(t_list **lst, char *key, char *value)
{
	t_list *node;

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
		printf("declare -x %s", tmp->key);
		if (tmp->value)
			printf("=\"%s\"\n", tmp->value);
		else
			printf("\n");
		lst = lst->next;
	}
}
int main(int ac, char **av, char **ev)
{
	t_list  *lst = NULL;
	char *str = "ABC=AAA";
	char *str1 = "ABC=BBB";
	char *str2 = "ABC+=CCC";
	char *str3 = "ABC";
	char *str4 = "BBB";
	char *str5 = "CCC=";


	create_lst(&lst, ev);
	export(&lst, str);
	printf("Export com ABC criado.\n");
	show_envars(lst);
	printf("======================================================================================================================================\n");
	printf("Export com ABC editado.\n");
	export(&lst, str1);
	show_envars(lst);
	printf("======================================================================================================================================\n");
	printf("Export com ABC appended.\n");
	export(&lst, str2);
	show_envars(lst);
	printf("======================================================================================================================================\n");
	printf("Export quando ABC n tem nada e ja existe\n");
	export(&lst, str3);
	show_envars(lst);
	printf("======================================================================================================================================\n");
	printf("Export quando BBB n tem nada e nao existe existe\n");
	export(&lst, str4);
	show_envars(lst);
	show_export(lst);
	printf("======================================================================================================================================\n");
	printf("Export quando CCC= \n");
	export(&lst, str5);
	show_envars(lst);
	show_export(lst);
	return (0);
}
