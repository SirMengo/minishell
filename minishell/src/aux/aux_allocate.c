/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_allocate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:33:59 by vampaier2         #+#    #+#             */
/*   Updated: 2025/11/18 11:11:00 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "aux.h"


int	is_special(char c)
{
	return (c == '<' || c == '>' || c == '|' || c == '"' || c == '\'');
}

int	handle_quotes(char **tab, const char *s, int start, char *quote_flag)
{
	int	len;
	int	content_len;

	len = 1; // 1 = start quote
	*quote_flag = s[start];
	
	// Find the closing quote
	while (s[start + len] && s[start + len] != *quote_flag)
		len++;
	
	if (s[start + len] == *quote_flag)
		len++; // include closing quote
	
	// Process environment variables within quotes
	// Start AFTER the opening quote (start + 1)
	// Process only the content (len - 2, excluding both quotes)
	content_len = len - 2;
	detect_envar(tab, s, start + 1, &content_len);
	return (len);  // Return the original length (with quotes)
}

int	handle_word(char **tab, const char *s, int start, char sep)
{
	int		len;
	int		processed_len;
	char	quote_flag;

	len = 0;
	quote_flag = 0;
	
	if (s[start] == '"' || s[start] == '\'')
	{
		len = handle_quotes(tab, s, start, &quote_flag);
	}
	else
	{
		// Find the end of the word (no quotes)
		while (s[start + len] && s[start + len] != sep && !is_special(s[start + len]))
			len++;
		
		// Process environment variables in unquoted word
		// detect_envar will set tab[0] to the expanded string
		processed_len = len;
		detect_envar(tab, s, start, &processed_len);
	}
	
	return (len);
}
