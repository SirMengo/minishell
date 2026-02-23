/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:49:35 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/22 16:59:49 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_FREE_H
# define EXIT_FREE_H

# include "../main.h"
//ft_free.c
void	free_arr(char **str);
//free_contents.c
void	free_env(void *content);
void	close_fds(t_cmd **contents);
//exit_free.c
void	exit_free(int err);
void	exit_error(void);

#endif