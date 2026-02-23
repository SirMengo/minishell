/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:09:42 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/22 17:28:47 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_H
# define ARG_PARSER_H

# include "../main.h"

int		open_redirect(char *name);
int		open_append(char *name);
int		open_input(char *name);
int		open_fd(char *name, int *arg_fd, int (*func)(char *));
char	**lst_to_arr(t_list *lst);
int		add_to_list(char *content, t_list **lst);
void	clean_cmd(t_cmd *cmd);
void	clean_cmd_arr(void);
t_cmd	**init_arg(void);

#endif