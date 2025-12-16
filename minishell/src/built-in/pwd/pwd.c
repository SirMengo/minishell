/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:17:15 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/16 14:56:56 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

int	pwd(void)
{
	char	str[PATH_MAX];

	if (getcwd(str, PATH_MAX) == NULL)
	{
		perror("pwd:");
		return (1);
	}
	printf("%s\n", str);
	return (0);
}
