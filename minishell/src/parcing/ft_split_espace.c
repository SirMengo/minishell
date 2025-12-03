/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_espace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:11:56 by xalves            #+#    #+#             */
/*   Updated: 2025/12/02 12:38:03 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"


//--------------------Count Words--------------------------

char const *countwords_aux(char const *s, char sep, char *quote_flag)
{
    while (*s)
    {
        checkforquotes(*s, quote_flag);
        if (*quote_flag == 0 && (*s == '|' || *s == '<' || *s == '>'))
            break;
        s++;
        if (*quote_flag == 0 && *s == sep)
            break;
    }
    return s;
}

int ft_count_words(char const *s, char sep)
{
    int 	word_count;
    char	quote_flag;
    int		ret;

    word_count = 0;
    quote_flag = 0;
    ret = 0;
    while (*s)
    {
        while (*s == sep)
            s++;
        if (!*s)
            break;
        ret = checkfortokens(&s, &quote_flag, &word_count);
        if (ret == -1)
            return (printf("\nSyntax error: unexpected '\\'\n"), -1);
        if (ret == 1)
            continue;
        word_count++;
        s = countwords_aux(s, sep, &quote_flag);
        if (s == NULL) //Check countwords_aux return == NULL (\)
            return (printf("\nSyntax error: unexpected '\\'\n"), -1);
    }
    return (word_count);
}

//---------------------------------------

static int checktokenret(int ret, char ***tab_p, char const *start, char const *s)
{
    if (ret == 1)
    {
        **tab_p = ft_substr(start, 0, s - start);
        (*tab_p)++;
        return (1); // indicate that caller should `continue`
    }
    return (0);
}


static int ft_allocate(char **tab, char const *s, char sep)
{
    char        **tab_p = tab;
    char        quote_flag;
    int         dummy_wc; // just because i don't use word_cont but i use it on a function
    int         ret;
    char const  *start;

    dummy_wc = 0;
	quote_flag = 0;
    while (*s)
    {
        while (*s == sep)
            s++;
        if (!*s)
            break;
        start = s; // 1. Try token first (| or <> groups)
        ret = checkfortokens(&s, &quote_flag, &dummy_wc);
        if (checktokenret(ret, &tab_p, start, s))
            continue;
        start = s;
        s = countwords_aux(s, sep, &quote_flag);
        *tab_p = ft_substr(start, 0, s - start);
        tab_p++;
    }
	return (*tab_p = NULL, 0);
}

char	**ft_split_espace(char const *s)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, ' ');
	printf("\nword_count =%d", size);
	if (size == -1)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	if(ft_allocate(new, s, ' ') == -1)
		return (NULL);
	return (new);
}




/* static void	ft_allocate(char **tab, const char *s, char sep)
{
	int		i;
	int		start;
	char	quote_flag;

	i = 0;
	start = 0;
	quote_flag = 0;
	while (s[start])
	{
		while (s[start] == sep)
			start++;
		if (!s[start])
			break ;
		if ((s[start] == '<' || s[start] == '>') && s[start + 1] == s[start])
		{
			tab[i++] = ft_substr(s, start, 2);
			start += 2;
		}
		else if (is_special(s[start]) && quote_flag == 0 && s[start] != '"' && s[start] != '\'')
		{
			tab[i++] = ft_substr(s, start, 1);
			start++;
		}
		else
			start += handle_word(&tab[i++], s, start, sep);
	}
	tab[i] = NULL;
}

//-------------------------------------------------------------
int	ft_count_words2(char const *s, char sep, int *error_flag)
{
	int		i;
	int		count;
	char	quote_flag;

	i = 0;
	count = 0;
	quote_flag = 0;
	*error_flag = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (!s[i])
			break ;
		if ((s[i] == '<' || s[i] == '>') && s[i + 1] == s[i] && quote_flag == 0)
		{
			count++;
			i += 2;
		}
		else if ((s[i] == '<' || s[i] == '>' || s[i] == '|') && quote_flag == 0)
		{
			count++;
			i += 1;
		}
		else
		{
			count++;
			if (s[i] == '"' || s[i] == '\'')
			{
				quote_flag = s[i++];
				while (s[i] && s[i] != quote_flag)
					i++;
				if (s[i] == '\0')
				{
					*error_flag = 1; // set error
					return (count);
				}
				i++;
				quote_flag = 0;
			}
			else
			{
				while (s[i] && s[i] != sep && s[i] != '<' && s[i] != '>'
					&& s[i] != '|' && s[i] != '"' && s[i] != '\'')
					i++;
			}
		}
	}
	return (count);
}


char **ft_split2(char const *s, char c)
{
	char	**new;
	int		size;
	int		error_flag;

	if (!s)
		return (NULL);
	size = ft_count_words2(s, c, &error_flag);
	if (error_flag)
	{
		printf("Syntax error: unclosed quotes\n");
		return (NULL); // donâ€™t allocate anything
	}
	new = malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new); 
} */