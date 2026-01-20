/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:18:50 by xalves            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/10/23 15:18:26 by msimoes          ###   ########.fr       */
=======
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:18:50 by xalves            #+#    #+#             */
/*   Updated: 2026/01/05 14:10:30 by vampaier2        ###   ########.fr       */
>>>>>>> origin/parcing
=======
/*   Updated: 2026/01/14 11:46:36 by msimoes          ###   ########.fr       */
>>>>>>> execution
/*                                                                            */
/* ************************************************************************** */

# include "aux.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node ->content = content;
	new_node ->next = NULL;
	new_node ->prev = NULL;
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	while (lst)
	{
		// Apply function to content
		new_content = f(lst->content);
		// Create new node with transformed content
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		// Add new node to end of new list
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	
	if (!lst || !new)
	return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
	last = last->next;
	last->next = new;
	new->prev = last;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst || !lst || !del)
		return ;
	if ((*lst)->prev)
		((*lst)->prev)->next = NULL;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

void	ft_lstdelone(t_list **start, t_list *node, void (*del)(void *))
{
	if(start != NULL && *start != NULL && node != NULL && del != NULL)
	{
		if (*start == node)
			*start = (**start).next;
		if (node->prev != NULL)
			node->prev->next = node->next;
		if (node->next != NULL)
			node->next->prev = node->prev;
		del(node->content);
		free (node);
	}
}

/*
List Examples :

t_list	*cmds;

cmds = NULL;

- To create a new node
ft_lstadd_back(&cmds, ft_lstnew(init_cmd(manager.cmd[i])));
				ref	,	ft_lstnew(initialize new node with content)
- To acess the variable
(t_command *)cmds->content

*/