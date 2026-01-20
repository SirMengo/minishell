/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:19:06 by vampaier2         #+#    #+#             */
/*   Updated: 2026/01/20 14:38:45 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_envar
{
	char			*name;
	char			*value;
	struct s_envar	*next;
}	t_envar;

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