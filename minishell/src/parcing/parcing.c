/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:23:06 by vampaier2         #+#    #+#             */
/*   Updated: 2025/12/03 15:43:19 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

//-------------------Lexer----------------------
int lexer(t_manager *manager)
{
    manager->cmd = ft_split_espace(manager->input);
    if(manager->cmd == NULL)
        return(1);
    return (0);
}

int checkfordolar(char *str)
{
    int		i;
    char	quote_flag;
    
	i = 0;
    quote_flag = 0;
	while(str[i] != '\0')
    {
		if((str[i] == '"') || (str[i] == '\''))
        {
            if(quote_flag != 0 && quote_flag == str[i])
                quote_flag = 0;
            else if(quote_flag == 0)
                quote_flag = get_quote_flag(str[i]);
        }
        if((str[i] == '$' && quote_flag == 0) || (str[i] == '$' && quote_flag == '"') )
            return(1);
        i++;
    }
    return(0); 
}

//------------------Expansions-----------------------------
void checkforexpansion(t_manager *manager)
{
    int		i;

	i = 0;
    while(manager->cmd[i] != NULL)
    {
        if(checkfordolar(manager->cmd[i]))
            printf("\n[%d]Detected $.", i);
		else
			printf("\n[%d]No Dola.", i);
        i++;
    }
    /* char	**aux_cmd;
    int		idx;

	i = 0;
    aux_cmd = manager->cmd;
	free(manager->cmd);
    printf("\n\naux_cmd[0]=%s", aux_cmd[0]);
	while(aux_cmd[i]) // run thru all strings
	{
		
		i++;
	}
	ft_striteri(s,f); */
}
//-------------------------------------------------------
int parcing(t_manager *manager)
{
    //printf("\nEntrou Parcing");
    if(checkunclosedquotes(manager) == 1)
        return(1);
    if(lexer(manager) == 1)
        return(1);
    if(checkinvalidtokens(manager) == 1)
        return (1);
    checkforexpansion(manager);
    return (0);
}

