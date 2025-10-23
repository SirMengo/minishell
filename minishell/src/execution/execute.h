/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:39:54 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/23 15:10:59 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../main.h"
# include "../aux/aux.h"

void	create_lst(t_list **lst, char **ev);
void	exports(t_list	*lst);
int		find_key(char *envars);
int		find_value(char *envars, int key_end);
void	fatal_error(const char *msg, t_list *lst, char *key, char *value);
void	unset(t_list **lst, char *str);
void	free_envar(void *content);
void	show_envars(t_list *lst);


#endif