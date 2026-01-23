/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:38:03 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/23 15:24:17 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H

# include "../structs.h"
# include <stddef.h>
# include <sys/types.h>
//Boolean
# include <stdbool.h>
# include "ft_printerr/ft_printf.h"

char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *str, int c, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_count_words(char const *s, char sep);
int		ft_count_words2(char const *s, char sep);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strnstr(const char *b, const char *l, size_t len);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_findchar(char *str, char c);
int		arr_size(char **arr);

int		checkforsignals(t_manager *manager);
void	setup_signals(void);
int		invalid_envar_c(char c);

// list
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list **start, t_list *node, void (*del)(void *));
int		ft_lstsize(t_list *lst);

//envars
t_envar	*init_envar(char *key, char *value);
//get_list
t_data	*data(void);

#endif
