/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:14:16 by xalves            #+#    #+#             */
/*   Updated: 2025/12/18 10:47:29 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#ifndef ECHOCTL
# define ECHOCTL 0001000
#endif

# include "aux/aux.h"
# include "built-in/builtin.h"

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

size_t		ft_strlen(const char *s);

typedef struct s_manager
{
	int		signal;
	char	*input;
	char**	cmd;
}			t_manager;

typedef struct s_args
{
	//int		argc;
	char	**arg;
}			t_args;

typedef struct s_command
{
	//int		argc;
	char*		cmd;
	//t_args				args;
}			t_command;

#endif
