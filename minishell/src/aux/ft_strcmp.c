/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:49:41 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/21 13:13:43 by msimoes          ###   ########.fr       */
=======
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:55:55 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/05 14:08:02 by vampaier2        ###   ########.fr       */
>>>>>>> origin/parcing
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	ft_strcmp(char *s1, char *s2)
{
<<<<<<< HEAD
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
//     char a[] = "aaaaa";
//     char b[] = "bbbbb";
//     printf("%d \n", ft_strcmp(a,b));
//     printf("%d \n", ft_strcmp(a,a));
//     printf("%d", ft_strcmp(b,a));
// }
=======
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return (0);
		}
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
}
>>>>>>> origin/parcing
