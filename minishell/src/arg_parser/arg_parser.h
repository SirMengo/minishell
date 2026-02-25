/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:11:03 by xalves            #+#    #+#             */
/*   Updated: 2026/02/25 13:11:06 by xalves           ###   ########.fr       */
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