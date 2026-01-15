/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:27:58 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/12 10:35:19 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	else
		return (NULL);
	return (0);
}

/*
int main()
{
	char str1[] = "Hello World";
	char character1 = 'o';
	char character2 = 'c';

	printf("Search for character '%c' in string '%s'\n", character1, str1);
	printf("Output: '%s'\n", ft_strchr(str1, character1));

	printf("Search for character '%c' in string '%s'\n", character2, str1);
	printf("Output: '%s'\n", ft_strchr(str1, character2));
}
*/