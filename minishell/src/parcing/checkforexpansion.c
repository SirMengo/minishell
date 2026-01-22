/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkforexpansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:17:55 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/21 16:13:01 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//------------------Expansions-----------------------------
//strdup so it allocates memory for me to free
// replace this with the function to get envar
char	*exp_envar(char	*envar_name)
{
	(void)envar_name;
	return (ft_strdup("ls -l"));
}

char	*getenvarval(char *s, int start, int *i)
{
	char	*straux;
	char	*result;

	*i = start + 1;
	while (s[*i] && invalid_envar_c(s[*i]) == 0)
		(*i)++;
	straux = ft_substr(s, start + 1, *i - (start + 1));
	result = find_envar(straux);
	free(straux);
	return (result);
}

char	*strjoin_free_left(char *left, char *right)
{
	char	*new;

	if (!left && !right)
		return (NULL);
	if (!left)
		return (ft_strdup(right));
	if (!right)
		return (left);
	new = ft_strjoin(left, right);
	free(left);
	free(right);
	return (new);
}

void	checkforexpansion(t_manager *manager)
{
	int		i;
	char	*tmp;

	i = 0;
	while (manager->cmd[i])
	{
		if (checkfordolar(manager->cmd[i]))
		{
			tmp = handle_envarargs(manager->cmd[i]);
			free(manager->cmd[i]);
			manager->cmd[i] = tmp;
		}
		tmp = removequotes(manager->cmd[i]);
		if (tmp != manager->cmd[i])
		{
			free(manager->cmd[i]);
			manager->cmd[i] = tmp;
		}
		i++;
	}
}
