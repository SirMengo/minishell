/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:38:03 by msimoes           #+#    #+#             */
/*   Updated: 2025/10/23 15:12:20 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H

# include <stddef.h>
# include "../main.h"

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
void	free_arr(char **str);
char	*ft_strnstr(const char *b, const char *l, size_t len);

// list
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list **start, t_list *node, void (*del)(void *));
//envars
t_envar *init_envar(char *key, char *value);

#endif
