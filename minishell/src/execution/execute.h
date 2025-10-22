/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:39:54 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/21 16:16:58 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../main.h"
# include "../aux/aux.h"

void	create_lst(t_envar **lst, char **ev);
void	exports(t_envar	*lst);
int		find_key(char *envars);
int		find_value(char *envars, int key_end);
void	fatal_error(const char *msg, t_envar *lst, char *key, char *value);
void	unset(t_envar *lst, char *str);

#endif