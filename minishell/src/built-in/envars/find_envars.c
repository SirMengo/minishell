/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_envars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:35:00 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/25 13:11:42 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

char	*find_key(char *st)
{
	int		i;
	char	*key;

	i = 0;
	while (st[i] != '=' && st[i] != '\0')
		i++;
	if (i > 0 && st[i] == '=' && st[i - 1] == '+')
		i--;
	key = ft_substr(st, 0, i);
	return (key);
}

char	*find_value(char *st)
{
	int		start;
	char	*value;

	start = 0;
	while (st[start] != '=' && st[start] != '\0')
		start++;
	if (st[start] == '\0')
		return (NULL);
	start++;
	if (st[start] == '\0')
		return (ft_strdup(""));
	value = ft_strdup(&st[start]);
	return (value);
}

int	is_append(char *st)
{
	int	i;

	i = 0;
	while (st[i] != '=' && st[i] != '\0')
		i++;
	if (i > 0 && st[i] == '=' && st[i - 1] == '+')
		return (1);
	return (0);
}
