/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:38:03 by msimoes           #+#    #+#             */
/*   Updated: 2025/11/25 14:42:36 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H

# include <stddef.h>
# include "../main.h"
# include "../execution/execute.h"
# include <signal.h>

typedef struct s_envar
{
	char 			*name;
	char			*value;
	struct	s_envar	*next;
}	t_envar;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_manager
{
	int		signal;
	char	*input;
	char**	cmd;
}			t_manager;

typedef struct s_args
{
	char	**arg;
}			t_args;

typedef struct s_command
{
	//int		argc;
	char	*cmd;
	char	**args;
	//t_args		args;
}			t_command;

void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin2(char const *s1, char const *s2);

int		ft_count_words(char const *s, char sep);
int		ft_count_words2(char const *s, char sep, int *error_flag);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strnstr(const char *b, const char *l, size_t len);

//free functions
void	free_arr(char **str);
void	free_command(void *ptr);


// list
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);

// signals
void	handle_signal(int sig, siginfo_t *info, void *context);
void	setup_signals(void);
int		checkforsignals(t_manager *manager);

// aux_allocation
 int	is_special(char c);
 int	handle_quotes(char **tab, const char *s, int start, char *quote_flag);
 int	handle_word(char **tab, const char *s, int start, char sep);
 int	skip_separators(const char *s, char sep, int start);
 
// envar
void	detect_envar(char **tab, char const *s, int start, int *len);


#endif