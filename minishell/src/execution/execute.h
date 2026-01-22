/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:58:21 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/22 14:55:16 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

#include "../main.h"

//aux.c
char	**conv_env();
//err_handler.c
int		err_handler(char *str, int err, char *cmd);
//paths.c
char	*find_path(char	*envp[], char *cmd);
//pipe_aux.c
void	close_pipes(int *fd);
//execution.c
void	cmd_exec(char **arg);

int		is_builtin(char **arr);

#endif