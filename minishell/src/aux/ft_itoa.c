/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:55:21 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/07 12:36:59 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	populate_str(int n, unsigned int size, char *str)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		if (n == -2147483648)
		{
			str[i] = '2';
			i++;
			n = 147483648;
		}
		else
			n = n * -1;
	}
	if (n == 0)
		str[i] = '0';
	else
	{
		while (size > i)
		{
			str[--size] = (n % 10) + '0';
			n = n / 10;
		}
	}
}

int	count_size(int n)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		else
		{
			n = n * -1;
			i++;
		}
	}
	if (n == 0)
		return (1);
	if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*conv;
	unsigned int	size;

	size = count_size(n);
	conv = ft_calloc(size + 1, sizeof(char));
	if (!conv)
		return (NULL);
	conv[size] = '\0';
	populate_str(n, size, conv);
	return (conv);
}
/*
int main()
{
	printf("%s \n" ,ft_itoa(0));
	printf("%s \n" ,ft_itoa(-2147483648));
	printf("%s" ,ft_itoa(2147483647));
}*/
