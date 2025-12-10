/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:39:54 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/10 14:26:04 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../main.h"
# include "../aux/aux.h"

//CD
int		cd(t_list **lst, char *str);
int		create_pwd(t_list **lst, char *cwd);
int		create_opwd(t_list **lst, char *cwd);
//ECHO
int		echo(char **av);
//ENVARS
void	create_lst(t_list **lst, char **ev);
void	show_envars(t_list *lst);
char	*find_envar(t_list *lst, char *str);
void	free_envar(void *content);
int		is_append(char *st);
char	*find_value(char *st);
char	*find_key(char *st);
//EXIT
int		ft_exit(char **av);
//EXPORTS
int		add_parser(t_list **lst, char *st);
int		update_existing(t_envar *aux, char *key, char *value);
int		init_export(t_list **lst, char *st);
int		export(t_list **lst, char **arr);
void	show_export(t_list *lst);
int		add_export(t_list **lst, char *key, char *value);
int		append_export(t_list *lst, char *key, char *value);
void	free_key_value(char *key, char *value);
//PWD
int		pwd();
//UNSET
void	unset(t_list **lst, char *str);
#endif