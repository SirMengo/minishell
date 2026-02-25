/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:49:35 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/25 13:12:06 by xalves           ###   ########.fr       */
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