/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:32:24 by vampaier2         #+#    #+#             */
/*   Updated: 2026/02/25 10:56:39 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

# include <stddef.h>
# include "../structs.h"
# include "../main.h"
# include "../execution/execute.h"

int		parcing(void);
int		checkunclosedquotes(void);
char	**ft_split_espace(char const *s);
void	checkforquotes(char c, char *quote_flag);
int		checkfortokens(char const **s, char *quote_flag, int *word_count);
int		checktokenstr(int idx, char firstchar);
int		checkinvalidtokens(void);
char	get_quote_flag(char c);
char	*removequotes(char *str);
int		checkfordolar(char *str);

t_args	*init_cmd(char **content);
char	*detect_cmd(char *content);

// Expansion
void	checkforexpansion(void);
char	*handle_envarargs(char *s);
char	*strjoin_free_left(char *left, char *right);
char	*getenvarval(char *s, int start, int *i);

void	preparelist(void);

#endif