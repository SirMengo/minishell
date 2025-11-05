/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:39:54 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/05 11:50:50 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../main.h"
# include "../aux/aux.h"

void	create_lst(t_list **lst, char **ev);
int		export(t_list **lst, char *st);
char	*find_key(char *st);
char	*find_value(char *st);
int		is_append(char *st);
void	fatal_error(const char *msg, t_list *lst, char *key, char *value);
void	unset(t_list **lst, char *str);
void	free_envar(void *content);
void	show_envars(t_list *lst);
void	show_export(t_list *lst);
char	*find_envar(t_list *lst, char *str);
void	append_export(t_list *lst, char *key, char *value);
void	add_export(t_list **lst, char *key, char *value);
int		ft_free(t_list *lst ,char *key, char *value);

#endif