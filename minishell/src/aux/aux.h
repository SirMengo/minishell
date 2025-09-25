/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:12:25 by xalves            #+#    #+#             */
/*   Updated: 2025/09/25 12:00:30 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H

# include "../main.h"

char	**ft_split(char const *s, char c);
static int	ft_count_words(char const *s, char sep);

// ft_calloc
void	*ft_calloc(size_t nmemb, size_t size);


#endif
