/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:47:28 by vampaier2         #+#    #+#             */
/*   Updated: 2025/11/18 11:03:09 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "aux.h"

int	invalid_envar_c(char c)
{
	// Check for invalid characters
	if (c == '$' || c == ' ' || c == '"' || c == '\'' || c == '=' || c == ':' || 
		c == ';' || c == '|' || c == '&' || c == '>' || c == '<' || c == '*' || 
		c == '?' || c == '!' || c == '(' || c == ')' || c == '[' || c == ']' || 
		c == '{' || c == '}' || c == '+' || c == '-' || c == '/' || c == '\\' || 
		c == '.' || c == ',' || c == '~')
	{
		return (1);  // Invalid character
	}
	return (0);  // Valid character
}

//is_valid_envar(s[start + len], quote_flag)
void	detect_envar(char **tab, char const *s, int start, int *len)
{
    char	quote_flag;
    char	*result;
    int		i;
	//int		envar_flag;
	
	i = 1;
	//envar_flag = 0;
    result = NULL;
	if (s[start] == '"')
		quote_flag = s[start];
	else if (s[start] == '\'')
		quote_flag = s[start];
	else
		quote_flag = 0;
	//printf("\ns[start] -> %c", s[start]);
	printf("\ns[start + len] -> %c\n", s[start + *len]);
	//printf("\nquote_flag -> %c", quote_flag);
	if (s[start + *len] == '$' && quote_flag != '\'')
	{
		printf("\n\tentrou");
		// nao entra
		while ((quote_flag == 0 && s[start + i] != ' '))
		{
			printf("\n\t\tentrou2");
			//printf("\n\t\t i = %d", i);
			// LOPPE INFINITA
			if(s[start + i] == '$')
			{
				*len += i; // save leng
				result = ft_strjoin2(result, ft_substr(s, start, i - 1));
				start = i;
				i = 0;
				while (invalid_envar_c(s[start + (i + 1)]) != 1)
					i++;
				result = ft_strjoin2(result, "$");
				//result = ft_strjoin(result, ft_substr(s, start, i - 1));
			}
			i++;
		}
		*tab = result;
	}
}