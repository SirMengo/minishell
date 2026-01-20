/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:38:03 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/28 11:28:17 by msimoes          ###   ########.fr       */
=======
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:38:03 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/05 13:57:32 by vampaier2        ###   ########.fr       */
>>>>>>> origin/parcing
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H

# include <stddef.h>
# include "../structs.h"
# include "../main.h"
<<<<<<< HEAD
# include "ft_printerr/ft_printf.h"

typedef struct s_envar
{
	char 			*key;
	char			*value;
}	t_envar;

typedef struct s_list
{
	void			*content;
	struct s_list	*next; 	
	struct s_list	*prev;
}	t_list;

=======
# include "../execution/execute.h"
# include <signal.h>



>>>>>>> origin/parcing
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
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_findchar (char *str, char c);

//free functions
void	free_arr(char **str);
void	free_command(void *ptr);


// list
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
<<<<<<< HEAD
void	ft_lstdelone(t_list **start, t_list *node, void (*del)(void *));
//envars
t_envar *init_envar(char *key, char *value);
=======

// signals
void	handle_signal(int sig, siginfo_t *info, void *context);
void	setup_signals(void);
int		checkforsignals(t_manager *manager);
>>>>>>> origin/parcing

// aux_allocation
 int	is_special(char c);
 int	handle_quotes(char **tab, const char *s, int start, char *quote_flag);
 int	handle_word(char **tab, const char *s, int start, char sep);
 int	skip_separators(const char *s, char sep, int start);
 
// envar
void	detect_envar(char **tab, char const *s, int start, int *len);

int		ft_strcmp(char *s1, char *s2);

#endif