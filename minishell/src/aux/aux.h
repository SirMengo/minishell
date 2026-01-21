/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:38:03 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/20 14:42:46 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H

# include <stddef.h>
# include <sys/types.h>
//Boolean
# include <stdbool.h>

# include "ft_printerr/ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next; 	
	struct s_list	*prev;
}	t_list;

typedef struct s_manager t_manager;

typedef struct s_data
{
	t_list			*env;
	t_manager		*manager;
	int				err_code;
	int				fd_lastin;
	bool			in_child;
}	t_data;

typedef struct s_cmd
{
	char			*str; //ARG
	char			**arr;
	int				fd_in;
	int				fd_out;
	int				fd_pipe[2];
	pid_t			pid;
}	t_cmd;

typedef struct s_envar
{
	char 			*key;
	char			*value;
}	t_envar;

char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *str, int c, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
char	**ft_split2(char const *s, char c);
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
int		ft_findchar (char *str, char c);
int		arr_size(char **arr);

// list
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list **start, t_list *node, void (*del)(void *));
int	ft_lstsize(t_list *lst);

//envars
t_envar *init_envar(char *key, char *value);
//get_list
t_data *data(void);


#endif
