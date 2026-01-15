/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:58:32 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/12 12:45:44 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	if (*l == '\0')
		return ((char *)(b));
	i = 0;
	while (i < len && b[i] != '\0')
	{
		j = 0;
		if (b[i] == l[0])
		{
			while ((i + j < len) && l[j] != '\0' && b[i + j] == l[j])
				j++;
			if (l[j] == '\0')
				return ((char *)(b + i));
		}
		i++;
	}
	return (0);
}

/*
int main()
{
	char str1[] = "Hello World!";
	char str2[] = "World";
	int i = 11;
	int j = 5;
	
	printf("Finding '%s' in '%s' within the first %d characters\n", 
			str2, str1, i);
	printf("Output: '%s'\n", ft_strnstr(str1, str2, i));

	printf("Finding '%s' in '%s' within the first %d characters\n",
			 str2, str1, j);
	printf("Output: '%s'\n", ft_strnstr(str1, str2, j));
}
*/