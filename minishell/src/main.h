/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:14:16 by xalves            #+#    #+#             */
/*   Updated: 2025/09/25 11:14:35 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "aux/aux.h"

// Standard I/O and memory
# include <stdio.h>  // printf, perror
# include <stdlib.h> // malloc, free, exit

// Readline
# include <readline/history.h>  // add_history, rl_clear_history
# include <readline/readline.h> // readline, rl_on_new_line, rl_replace_line,rl_redisplay

// File operations
# include <fcntl.h>  // open, O_* flags
# include <unistd.h> // read, write, close, access, dup, dup2, pipe, chdir,getcwd, execve, fork, isatty, ttyname, ttyslot

// Process and signals
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

typedef struct s_manager
{
	int		signal;
	char	*input;
	int		argc;
	char	**argv;

}		t_manager;

#endif
