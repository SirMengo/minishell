/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:47:28 by vampaier2         #+#    #+#             */
/*   Updated: 2025/11/18 11:11:23 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "aux.h"

// Valid characters for envars
	// - Letters: a-z, A-Z
	// - Digits: 0-9
	// - Underscore: '_'
int	invalid_envar_c(char c)
{	
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	if (c == '_')
		return (0);
	return (1);
}

char	get_quote_flag(const char *s, int start)
{
	// If the argument starts with a quote, we're inside that quote type
	if (s[start] == '"')
		return ('"');
	if (s[start] == '\'')
		return ('\'');
	return (0);
}

int	check_end_of_arg(char c, char quote_flag)
{
	// If no quotes, stop at null terminator or space
	if (quote_flag == 0)
	{
		if (c == '\0' || c == ' ')
			return (0);
		return (1);
	}
	// If in double quotes, stop at closing quote or null
	if (quote_flag == '"')
	{
		if (c == '"' || c == '\0')
			return (0);
		return (1);
	}
	// If in single quotes, stop at closing quote or null
	if (quote_flag == '\'')
	{
		if (c == '\'' || c == '\0')
			return (0);
		return (1);
	}
	return (0);
}

// Extract environment variable name and get its length
int	get_envar_name_len(const char *s, int pos)
{
	int	len;

	len = 0;
	// Skip the $ sign
	if (s[pos] == '$')
		pos++;
	
	// Count valid envar characters
	while (s[pos] != '\0' && !invalid_envar_c(s[pos]))
	{
		len++;
		pos++;
	}
	return (len);
}

char* exp_envar(char	*envar_name)
{
	(void)envar_name;
	return("HORSE");
}

// Main function to detect and expand environment variables
void	detect_envar(char **tab, char const *s, int start, int *len)
{
	char	quote_flag;
	char	*result;
	char	*envar_name;
	char	*envar_value;
	int		i;
	int		envar_len;
	int		original_len;

	i = 0;
	original_len = *len;  // Save the original length passed in
	result = ft_strdup("");
	quote_flag = get_quote_flag(s, start);

	// If original_len > 0, process exactly that many characters (from handle_quotes)
	// Otherwise, use check_end_of_arg for unquoted words
	while (s[start + i] != '\0' && 
		   (original_len > 0 ? (i < original_len) : check_end_of_arg(s[start + i], quote_flag)))
	{
		if (s[start + i] == '$' && quote_flag != '\'')
		{
			envar_len = get_envar_name_len(s, start + i);
			
			if (envar_len > 0)
			{
				envar_name = ft_substr(s, start + i + 1, envar_len);
				envar_value = exp_envar(envar_name);
				result = ft_strjoin2(result, envar_value);
				free(envar_name);
				i += envar_len + 1;
			}
			else
			{
				result = ft_strjoin2(result, "$");
				i++;
			}
		}
		else
		{
			char temp[2];
			temp[0] = s[start + i];
			temp[1] = '\0';
			result = ft_strjoin2(result, temp);
			i++;
		}
	}
	*tab = result;
	*len = i;
	//free(result);
}