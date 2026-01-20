/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:06:38 by msimoes           #+#    #+#             */
/*   Updated: 2025/09/29 14:23:36 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
int main()
{
	char str1[] = "Hello World";
	char str2[] = " ";
	char str3[] = "\n";

	printf("String 'Hello World': %lu \n" ,ft_strlen(str1));
	printf("String ' ': %lu \n" ,ft_strlen(str2));
	printf("String \\n: %lu \n" ,ft_strlen(str3));
}
*/