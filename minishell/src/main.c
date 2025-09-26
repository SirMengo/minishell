/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:30:58 by msimoes           #+#    #+#             */
/*   Updated: 2025/09/26 13:14:20 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// int	g_var;

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	new_str = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < s1_len && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len && s2[i])
	{
		new_str[s1_len + i] = s2[i];
		i++;
	}
	return (new_str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (aux_s1[i] == '\0' && aux_s2[i] == '\0')
		{
			return (0);
		}
		if (aux_s1[i] == '\0' || aux_s2[i] == '\0')
		{
			return ((unsigned int)(aux_s1[i] - aux_s2[i]));
		}
		if (aux_s1[i] != aux_s2[i])
		{
			return ((unsigned int)(aux_s1[i] - aux_s2[i]));
		}
		i++;
	}
	return (0);
}

// Detect functions

int	detect_command(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(str, "echo", len) == 0)
		return (1);
	if (ft_strncmp(str, "cd", len) == 0)
		return (1);
	if (ft_strncmp(str, "pwd", len) == 0)
		return (1);
	if (ft_strncmp(str, "export", len) == 0)
		return (1);
	if (ft_strncmp(str, "unset", len) == 0)
		return (1);
	if (ft_strncmp(str, "env", len) == 0)
		return (1);
	if (ft_strncmp(str, "exit", len) == 0)
		return (1);
	return (0);
}

int	detect_pipe(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(str, "|", len) == 0)
		return (1);
	return (0);
}

int	detect_redirections(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(str, "<", len) == 0)
		return (1);
	if (ft_strncmp(str, "<<", len) == 0)
		return (1);
	if (ft_strncmp(str, ">", len) == 0)
		return (1);
	if (ft_strncmp(str, ">>", len) == 0)
		return (1);
	return (0);
}

// missing detecting  '$?'
int	detect_env_var(char *str)
{
	if (ft_strncmp(str, "$", 1) == 0)
		return (1);
	return (0);
}

// -------------------------------------
int	main(void)
{
	static t_manager	manager;
	int					i;

	i = 0;
	while (manager.signal != SIGINT && manager.signal != SIGQUIT)
	{
		manager.input = readline("🐴");
		printf("finished reading -> %s\n", manager.input);
		 if (manager.input == NULL) // Ctrl-D pressed, EOF detected
		{
			printf("Ctrl-D pressed\n");
			free(manager.input);
			break ;
		}
		/*
		printf("finished reading -> %s\n", manager.input);
		manager.argc = ft_count_words(manager.input, ' ');
		printf("finished getting argc ->%d\n", manager.argc);
		manager.argv = ft_split(manager.input, ' ');
		free(manager.input);
		// get_argv(manager);
		printf("argv:\n");
		while (i < manager.argc)
		{
			if (detect_command(manager.argv[i]) == 1)
				printf("[%d(command)]%s\n", i, manager.argv[i]);
			else if (detect_pipe(manager.argv[i]) == 1)
				printf("[%d(pipe)]%s\n", i, manager.argv[i]);
			else if (detect_redirections(manager.argv[i]) == 1)
				printf("[%d(redirections)]%s\n", i, manager.argv[i]);
			else if (detect_env_var(manager.argv[i]) == 1)
				printf("[%d(Environment Variables)]%s\n", i, manager.argv[i]);
			else
				printf("[%d(arg)]%s\n", i, manager.argv[i]);
			i++;
		}
		if (manager.input && *manager.input) // if is not NULL or empty
			add_history(manager.input);
		printf("\n");
		i = 0; */
		free(manager.input);
	}
	free(manager.input);
	return (0);
}
