/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:12:25 by xalves            #+#    #+#             */
/*   Updated: 2025/09/25 16:57:43 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H

# include "../main.h"

char	**ft_split(char const *s, char c);
static int	ft_count_words(char const *s, char sep);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
