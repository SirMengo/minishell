/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:14:16 by xalves            #+#    #+#             */
/*   Updated: 2026/02/03 16:21:20 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# ifndef ECHOCTL
#  define ECHOCTL 0001000
# endif

# include "structs.h"
# include "aux/aux.h"
# include "parcing/parcing.h"
# include "hdocs/hdocs.h"
# include "arg_parser/arg_parser.h"
# include "built-in/builtin.h"
# include "error/error.h"
# include "execution/execute.h"
# include "exit_free/exit_free.h"

// Standard I/O and memory
# include <stdio.h>  // printf, perror
# include <stdlib.h> // malloc, free, exit

// Readline
# include <readline/history.h>  // add_history, rl_clear_history
# include <readline/readline.h> // readline, rl_on_new_line,
//  rl_replace_line,rl_redisplay

// File operations
# include <fcntl.h>  // open, O_* flags
# include <unistd.h> // read, write, close, access, dup, dup2,
//  pipe, chdir,getcwd, execve, fork, isatty, ttyname, ttyslot

// Process and signals
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>    // signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/types.h> // pid_t, stat types
# include <sys/wait.h>  // wait, waitpid, wait3, wait4
// File status
# include <errno.h>    // errno (used with strerror)
# include <string.h>   // strerror
# include <sys/stat.h> // stat, lstat, fstat

// Directory operations
# include <dirent.h> // opendir, readdir, closedir

// Terminal control
# include <sys/ioctl.h> // ioctl
# include <termios.h>   // tcgetattr, tcsetattr

// Termcap (Terminal capability functions)
# include <termcap.h> // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

// Environment
# include <stddef.h> // NULL

//Limits
# include <linux/limits.h>

int		ft_strcmp(char *s1, char *s2);

// HISTORY
void	addto_history(t_manager manager);
void	addtohistory_andclean(t_manager *manager);

void	free_arrstr(char **argv);

size_t	ft_strlen(const char *s);

#endif