/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:56:31 by xalves            #+#    #+#             */
/*   Updated: 2026/01/20 15:12:28 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup_str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	dup_str = malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);
	len = 0;
	while (s[len])
	{
		dup_str[len] = s[len];
		len++;
	}
	dup_str[len] = '\0';
	return (dup_str);
}
/*cc -Wall -Werror -Wextra ft_strdup.c ft_strlen.c
int	main(void)
{
	char	s[] = "Banana";
	char	*copy = ft_strdup(s);
	if(copy != NULL)
	{
		printf("OG = %s | Copy = %s\n",s,copy);
		printf("OG len = %lu |",ft_strlen(s) + 1);
		printf(" Copy len = %lu\n",ft_strlen(copy) + 1);
		free(copy);
	}
	else
		printf("Encontered a NULL");
	return (0);
} */
