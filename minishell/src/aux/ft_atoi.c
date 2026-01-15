/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:13:22 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/07 12:36:54 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				val;
	int				res;

	i = 0;
	val = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			val = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * val);
}

/*
int main()
{
	char str1[] = "-2147483648";
	char str2[] = "314";
	char str3[] = "0";
	
	printf("Converting the string '%s' \n", str1);
	printf("to the integer '%d'\n", ft_atoi(str1));
	printf("Converting the string '%s' \n", str2);
	printf("to the integer '%d'\n", ft_atoi(str2));
	printf("Converting the string '%s' \n", str3);
	printf("to the integer '%d'\n", ft_atoi(str3));
}
*/