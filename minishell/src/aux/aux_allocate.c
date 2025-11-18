/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_allocate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:33:59 by vampaier2         #+#    #+#             */
/*   Updated: 2025/11/06 15:43:39 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "aux.h"

int	is_special(char c)
{
	return (c == '<' || c == '>' || c == '|' || c == '"' || c == '\'');
}

static void	advance_len(char **tab, const char *s, int start, int *len)
{
	detect_envar(tab, s, start, len); // quote_flag can be replaced by s[start]
	(*len)++;
}

int	handle_quotes(char **tab, const char *s, int start, char *quote_flag)
{
	int	len;

	len = 1; // 1 = start quote
	*quote_flag = s[start];
	while (s[start + len] && s[start + len] != *quote_flag)
        advance_len(tab, s, start, &len);
	if (s[start + len] == *quote_flag)
		len++; // include last/closing quote
	return (len);
}

int	handle_word(char **tab, const char *s, int start, char sep)
{
	int		len;
	char	quote_flag;

	len = 0;
	quote_flag = 0;
	if (s[start] == '"' || s[start] == '\'')
		len = handle_quotes(tab, s, start, &quote_flag);
	else
	{
		while (s[start + len] && s[start + len] != sep && !is_special(s[start + len]))
            advance_len(tab, s, start, &len);
	}
	tab[0] = ft_substr(s, start, len);
	return (len);
}