/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:19:06 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/03 15:49:02 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
 
#include <stdbool.h>
#include <sys/types.h>
#include <signal.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_manager
{
	int		signal;
	char	*input;
	char	**cmd;
	t_list	*cmds;
}			t_manager;

//	content -> text
/*	type:
		- arg		(banana)
		- command	(echo, cd, pwd, export, unset, env, exit)
		- pipe		(|)
		- redirect	(>)
		- append	(>>)
		- input		(<)
		- heredoc	(<<)
*/
typedef struct s_args
{
	char	**content;
	char	**type;
}			t_args;

typedef struct s_command
{
	//int		argc;
	char	*cmd;
	char	**args;
	//t_args		args;
}			t_command;

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list; */

//typedef struct s_manager t_manager;

typedef struct s_data
{
	t_list			*env;
	t_manager		*manager;
	int				err_code;
	int				fd_lastin;
	bool			in_child;
}	t_data;

typedef struct s_cmd
{
	char			**arg;//ARG
	int				fd_in;
	int				fd_out;
	int				fd_pipe[2];
	int				execute;
	pid_t			pid;
}	t_cmd;

typedef struct s_envar
{
	char			*key;
	char			*value;
}	t_envar;

#endif