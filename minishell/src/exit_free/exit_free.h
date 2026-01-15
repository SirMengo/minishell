/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:49:35 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/14 12:14:25 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_FREE_H
# define EXIT_FREE_H

//ft_free.c
void	free_arr(char **str);
//free_contents.c
void	free_env(void *content);
//exit_free.c
void	exit_free(int err);

#include "../main.h"

#endif