/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:13:01 by xalves            #+#    #+#             */
/*   Updated: 2026/02/25 13:13:03 by xalves           ###   ########.fr       */
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