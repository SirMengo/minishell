/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:58:21 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/16 14:58:37 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

//aux.c
char	**conv_env();
//err_handler.c
int		err_handler(char *str, int err, char *cmd);
//paths.c
char	*find_path(char	*envp[], char *cmd);
//pipe_aux.c
void	close_pipes(int *fd);
//execution.c
void	cmd_exec(char *str);

#include "../main.h"

#endif