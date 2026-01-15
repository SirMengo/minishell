/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:12:32 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/12 10:24:32 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}

/*
int main()
{
	char str1[] = "Hello World";
	char carac1 = 'A';
	unsigned long num1 = 6;

	printf("String: %s \n", str1);
	printf("Filling %lu spots\n", num1);
	printf("with character '%c' \n",carac1);
	ft_memset(str1, carac1, num1);
	printf("Output: %s", str1);
}
*/