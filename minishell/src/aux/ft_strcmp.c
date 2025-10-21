/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:49:41 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/20 17:59:42 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
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
