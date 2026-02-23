/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:58:21 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/22 17:30:05 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../main.h"

//aux.c
char	**conv_env(void);
//err_handler.c
int		err_handler(char *str, int err, char *cmd);
//paths.c
char	*find_path(char	*envp[], char *cmd, bool *failed_abs);
//pipe_aux.c
void	close_pipes(int *fd);
//execution.c
void	cmd_exec(char **arg, int fd_pipe[2]);

int		is_builtin(char **arr);
//pipes.c
int		pipes(t_cmd **arr);
int		exec_in_parent(void);

#endif