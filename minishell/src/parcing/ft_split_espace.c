/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_espace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:11:56 by xalves            #+#    #+#             */
/*   Updated: 2026/01/06 14:45:21 by vampaier2        ###   ########.fr       */
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
    char        **tab_p;
    char        quote_flag;
    int         dummy_wc; // just because i don't use word_cont but i use it on a function
    int         ret;
    char const  *start;

    dummy_wc = 0;
	quote_flag = 0;
	tab_p = tab;
    while (*s)
    {
        while (*s == sep)
            s++;
        if (!*s)
            break;
        start = s; //check token first (| or <> groups)
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
	//printf("\nword_count =%d", size);
	if (size == -1)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	if(ft_allocate(new, s, ' ') == -1)
		return (NULL);
	return (new);
}
