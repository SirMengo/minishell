/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:17:31 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/06 11:22:22 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static int	check_exists(char *o_cwd, char *n_cwd)
{
	t_envar	*aux;
	t_list	*tmp;
	int		pwd;
	int		oldpwd;

	pwd = 0;
	oldpwd = 0;
	tmp = data()->env;
	while (tmp)
	{
		aux = (t_envar *)tmp->content;
		if (ft_strcmp(aux->key, "PWD") == 0)
			pwd = 1;
		if (ft_strcmp(aux->key, "OLDPWD") == 0)
			oldpwd = 1;
		tmp = tmp->next;
	}
	if (pwd == 0)
		return (create_pwd(n_cwd));
	if (oldpwd == 0)
		return (create_opwd(o_cwd));
	return (0);
}

static int	change_envar(t_envar *aux, char *o_cwd, char *n_cwd)
{
	char	*new_value;

	if (ft_strcmp(aux->key, "PWD") == 0)
	{
		new_value = ft_strdup(n_cwd);
		if (new_value == NULL)
		{
			ft_printerror("cd: memory allocation failed.");
			return (1);
		}
		free(aux->value);
		aux->value = new_value;
	}
	if (ft_strcmp(aux->key, "OLDPWD") == 0)
	{
		new_value = ft_strdup(o_cwd);
		if (new_value == NULL)
		{
			ft_printerror("cd: memory allocation failed");
			return (1);
		}
		free(aux->value);
		aux->value = new_value;
	}
	return (0);
}

static int	update_envar(char *o_cwd, char *n_cwd)
{
	t_envar	*aux;
	t_list	*tmp;

	tmp = data()->env;
	while (tmp)
	{
		aux = (t_envar *)tmp->content;
		if (change_envar(aux, o_cwd, n_cwd) != 0)
			return (1);
		tmp = tmp->next;
	}
	return (check_exists(o_cwd, n_cwd));
}

static int	cd_home()
{
	t_envar	*aux;
	t_list	*tmp;
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("cd");
		return (1);
	}
	tmp = data()->env;
	while (tmp)
	{
		aux = (t_envar *)tmp->content;
		if (ft_strcmp(aux->key, "HOME") == 0)
		{
			if (aux->value == NULL || aux->value[0] == '\0')
				return (ft_printerror("cd: HOME is empty\n"), 1);
			if (chdir(aux->value) == -1)
				return (perror("cd"), 1);
			else
				return (update_envar(cwd, aux->value), 0);
		}
		tmp = tmp->next;
	}
	return (ft_printerror("cd: HOME not set\n"), 1);
}

int	cd(char *str)
{
	char tmp[PATH_MAX];
	char n_cwd[PATH_MAX];
	
	if (!getcwd(tmp, PATH_MAX))
		return (perror("cd"), 1);
	if (!str)
		return (cd_home());
	if (*str == '\0')
		return (ft_printerror("cd: invalid empty path\n"), 1);
	if (chdir(str) != 0)
		return (perror("cd"), 1);
	if (!getcwd(n_cwd, PATH_MAX))
	{
		perror("cd");
		if (chdir(tmp) == -1)
			perror("cd");
		return (1);
	}
	if (update_envar(tmp, n_cwd) != 0)
	{
		if (chdir(tmp) == -1)
			perror("cd");
		return (1);
	}
	return (0);
}

/* TEST MAIN
int main(int ac, char **av, char **ev)
{
	char	input[PATH_MAX];
	char	cwd[PATH_MAX];

	create_lst(ev);
	while (1)
	{
		if (getcwd(cwd, sizeof(cwd)))
			printf("cwd: %s\n", cwd);

		printf("cd> ");
		if (!fgets(input, sizeof(input), stdin))
			break;

		// remove trailing newline
		input[strcspn(input, "\n")] = '\0';

		// exit condition
		if (strcmp(input, "exit") == 0)
			break;

		// simulate `cd` with no arguments
		if (strcmp(input, "cd") == 0)
			cd(NULL);
		else
			cd(input);
	}
	return (0);
}
*/