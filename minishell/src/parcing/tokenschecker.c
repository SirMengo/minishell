/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenschecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:32:22 by vampaier2         #+#    #+#             */
/*   Updated: 2025/12/02 15:33:45 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//----------------Tokens-----------------------

int checktokenstr(t_manager *manager, int idx, char firstchar)
{
    if(firstchar == '|')
        if(ft_strcmp("|", manager->cmd[idx]) == 0)
            return(0);
    if(firstchar == '<')
    {
        if(ft_strcmp("<", manager->cmd[idx]) == 0)
            return(0);
        else if(ft_strcmp("<<", manager->cmd[idx]) == 0)
            return(0);
    }
    if(firstchar == '>')
    {
        if(ft_strcmp(">", manager->cmd[idx]) == 0)
            return(0);
        else if(ft_strcmp(">>", manager->cmd[idx]) == 0)
            return(0);
    }
    return (printf("\nInvalid Token!!!\n"), 1);
}

int checkinvalidtokens(t_manager *manager)
{
    int i;
    char firstchar;
    
    i = 0;
    while(manager->cmd[i] != NULL)
    {
        firstchar = manager->cmd[i][0];
        if(firstchar =='|' || firstchar =='<' || firstchar =='>')
            if(checktokenstr(manager, i, firstchar) == 1)
                return (1);
        i++;
    }
    return (0);
}