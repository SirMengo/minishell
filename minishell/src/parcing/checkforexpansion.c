/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkforexpansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:17:55 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/19 14:04:46 by msimoes          ###   ########.fr       */
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

// Valid characters for envars
	// - Letters: a-z, A-Z
	// - Digits: 0-9
	// - Underscore: '_'
int	invalid_envar_c(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	if (c == '_')
		return (0);
	if (c == '?')
		return (0);
	return (1);
}

char	*getenvarval(char *s, int start, int *i)
{
	char	*straux;
	char	*result;
	//t_data	*data;
	
	//data = ;
	*i = start + 1;
	if (s[start + 1] == '?')
		return ( (*i)++, ft_itoa(data()->err_code));
	if (ft_isnum(s[start + 1]) == 1)
	{
		straux = ft_substr(s, start, start + 1);
		result = ft_strdup(find_envar(straux));
		free(straux);
		return ((*i)++, result);
	}
	while (s[*i] && invalid_envar_c(s[*i]) == 0)
		(*i)++;
	if (*i == start + 1)
		return (ft_strdup("$"));
	straux = ft_substr(s, start + 1, *i - (start + 1));
	result = ft_strdup(find_envar(straux));
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

void	checkforexpansion()
{
	int		i;
	char	*tmp;

	i = 0;
	while (data()->manager.cmd[i])
	{
		if (checkfordolar(data()->manager.cmd[i]))
		{
			tmp = handle_envarargs(data()->manager.cmd[i]);
			printf("	Temp (%s)\n", tmp);
			printf("	Cmd (%s)\n", data()->manager.cmd[i]);

			free(data()->manager.cmd[i]);
			data()->manager.cmd[i] = tmp;
		}
		i++;
	}
}
