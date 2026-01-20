/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:56:31 by xalves            #+#    #+#             */
/*   Updated: 2025/11/05 13:01:13 by msimoes          ###   ########.fr       */
=======
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:56:31 by xalves            #+#    #+#             */
/*   Updated: 2026/01/05 14:08:16 by vampaier2        ###   ########.fr       */
>>>>>>> origin/parcing
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
