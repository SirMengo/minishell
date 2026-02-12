/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:39:54 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/12 17:15:38 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../main.h"

//CD
int		cd(char **arr);
int		create_pwd(char *cwd);
int		create_opwd(char *cwd);
int		update_envar(char *o_cwd, char *n_cwd);
int		check_exists(char *o_cwd, char *n_cwd);

//ECHO
int		echo(char **av);
//ENVARS
void	create_lst(char **ev);
void	show_envars(void);
char	*find_envar(char *str);
void	free_envar(void *content);
int		is_append(char *st);
char	*find_value(char *st);
char	*find_key(char *st);
void	init_env(char **ev);
//EXIT
int		ft_exit(char **av);
//EXPORTS
int		add_parser(char *st);
int		update_existing(t_envar *aux, char *key, char *value);
int		init_export(char *st);
int		export(char **arr);
void	show_export(void);
int		add_export(char *key, char *value);
int		append_export(char *key, char *value);
void	free_key_value(char *key, char *value);
//FREE
void	free_lists(void);
//PWD
int		pwd(void);
//UNSET
void	unset(char **arr);

#endif
