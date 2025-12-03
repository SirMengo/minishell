/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:30:58 by msimoes           #+#    #+#             */
/*   Updated: 2025/12/02 15:22:26 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return (0);
		}
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
}

// Detect functions

char	*ft_print_haru(void) // maybe think about using a get_next_line?
{
	char *haru;

	haru = "⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠈⢮⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⢻\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠈⡀⠈⢷⣝⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢟⣻⣯⡭⠟⠻⣿⣿⣿⣿⣿⣿⣿⡿⠟⢉⠠⠀⢾\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⠈⠄⠠⠁⡀⢉⠙⠪⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡿⣫⣮⣿⡟⣱⡰⢩⡓⢬⡎⢻⣿⠿⠛⢉⠀⢆⠈⠀⢠⢸\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⠈⠌⡀⠂⠡⠀⠂⠄⡀⠈⠻⣛⣭⢽⣷⣶⢬⣻⣯⣵⣦⣬⣶⡈⣐⠢⢓⢬⡎⣰⣧⢁⠂⠜⠠⠁⢀⠀⠠⡸⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠡⡀⠡⠀⠃⣀⣤⣤⣥⣐⠲⡙⣿⣿⣵⣾⣿⣿⣿⣿⣿⣿⣿⡷⠅⡃⡾⢠⣿⣿⣧⢈⠐⠁⠀⠀⠄⣱⢧⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠠⢁⠂⣡⣾⣿⣿⣿⠟⠿⡿⣶⣝⣿⣿⣿⣿⣿⣿⣿⠿⣛⣥⣶⡷⣶⣶⣼⢿⣿⡿⣄⠀⠠⠁⢈⣾⣏⣾⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⣢⣾⣿⣿⡟⡟⠁⠊⠁⠠⢈⠉⡉⢉⠡⢉⠉⠉⠓⢋⠩⠭⢭⢹⡘⣿⣿⣷⣝⢾⡿⣿⣶⡿⣷⣶⠖⣠⡽\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣑⡿⣳⣶⣷⠜⠀⠀⠀⡑⢈⣀⣑⣐⣂⣐⣂⣈⠂⠱⢀⠂⠄⡈⠀⠑⠸⡿⢿⣿⣷⣟⢿⢿⡛⣩⣴⢞⣫⣾\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⡟⣴⣛⣶⣽⡿⡞⡠⠦⣿⣿⡫⠍⣱⣽⣷⣿⣿⢿⡟⣿⢻⣶⣦⣌⡐⠀⠂⠀⣷⢯⢿⢿⣿⣮⢻⢁⡧⡜⡽⣿⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⡟⣼⣟⣿⣻⣿⡟⡰⡑⣾⣵⡾⣫⣻⢺⣿⣿⣿⣿⣿⢽⡗⣎⢿⣹⡾⣽⣷⣄⢀⢹⡷⣯⣿⣾⡽⣧⢸⡁⢳⠸⡼⣿\n"
			"⣿⣿⣿⣿⣿⣿⡿⣴⣿⣿⣿⢿⡷⠰⡑⡎⢿⣿⣣⣿⣏⣿⣿⣿⣿⣿⡟⣸⢗⣿⣮⡋⣿⣿⡟⣿⡧⢺⣿⣹⣿⣿⣿⣿⡆⣅⢨⢣⣷⢿\n"
			"⣿⣿⣿⣿⣿⣿⢧⣾⣿⣿⣿⣿⠃⡇⢽⣗⣯⣅⣿⣿⢯⢿⣿⣿⣿⣿⡥⣏⣽⣿⣿⣷⡿⢟⠅⣿⡿⢸⣿⣿⣿⢯⣿⡽⣷⠠⡃⠲⣼⣸\n"
			"⣿⣿⣿⣿⣿⡿⡌⣿⣿⣿⣽⡇⡹⠔⢸⣿⣾⢼⣷⢯⡞⢟⣿⣿⣿⣝⣴⣾⠿⢟⣻⣅⡾⡯⣟⡿⣏⢸⣿⣿⣾⣿⣯⢿⢹⠀⡃⢇⢻⣟\n"
			"⣿⣿⣿⣿⣿⢧⣿⣿⣟⣯⣿⠀⡳⡱⣼⡿⠛⣉⢉⡛⢻⣿⣾⣿⣽⣿⣿⣿⣿⣿⣿⣽⣾⣿⣿⡄⢻⢸⣿⣿⣿⣾⢿⣿⢸⢀⠇⠉⠻⣷\n"
			"⣿⣿⣿⣿⣿⣼⣿⣻⣯⣿⡇⠰⣰⣕⠋⣴⢯⡀⢠⢀⣠⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢿⣿⣿⣧⢸⣿⣿⣿⣟⣿⡟⢨⠨⢠⡀⣐⣀\n"
			"⣿⣿⣿⣿⡟⣿⣿⣛⣿⣯⠇⢤⣉⡟⢰⣿⠘⠃⣈⡮⠍⣿⣿⣿⣿⣿⣿⣿⣿⣷⠛⠛⠛⠾⣿⣿⣿⣾⣿⣿⣿⣻⣟⡇⠸⡆⠎⡥⣿⣿\n"
			"⣿⣿⣿⣿⡇⠇⣿⡁⣿⣾⠃⢦⡱⢿⣜⢿⣴⣿⣿⠿⣺⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣶⣄⡹⢯⣿⣿⣿⢻⡿⡽⠈⡖⠇⠈⠲⢹⣼\n"
			"⣿⣿⣿⣿⡇⣘⢻⡇⡿⣾⠁⡔⡹⡜⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣾⣿⣿⡟⢸⣿⠡⢓⢴⣀⠐⠀⠉⠉\n"
			"⣿⡿⠿⠿⠇⣏⠘⣷⣼⠸⣍⢣⠳⡍⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢷⣿⣿⡿⢁⣿⠃⠆⠭⡞⣌⠳⣒⢆⢿\n"
			"⡿⢿⣿⣿⣿⡽⠲⢻⣉⡇⢣⢀⠇⡽⢹⣿⣿⣿⣿⣿⣏⣾⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⡿⣾⣿⢯⢃⣺⠣⠙⢨⢵⠳⣌⠳⣥⢚⡜\n"
			"⣷⢰⣽⣏⢿⣿⢣⣌⢯⡐⢣⠆⣮⠘⡜⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⡟⣾⣿⣿⣿⡿⣹⡿⣽⢃⠦⣡⠣⢄⢧⠖⢣⢘⡳⡔⣫⠜\n"
			"⣿⠽⣇⣿⣏⣿⣧⡜⣮⢇⢋⡖⢹⣷⣄⣮⡻⣿⣿⣿⣿⡽⣿⣿⣿⣿⣿⡿⣽⣿⣿⣿⣿⣩⡿⣽⢃⢎⡖⣕⡜⣜⢪⣿⣦⡁⠕⢹⢆⡻\n"
			"⣿⡃⣿⣽⣯⣿⣿⣷⣜⢯⣂⠹⣆⠩⡻⣿⣿⣶⣝⠿⣿⣿⣾⣿⣿⣿⣿⣾⣿⣿⡿⢟⢎⡾⡽⢡⡚⣢⣪⠞⠌⣰⣿⣿⣿⣿⣷⣤⡙⢜\n"
			"⡿⢡⣿⣾⣿⣿⣿⣿⣿⣿⣷⡆⢣⡅⠹⣆⢙⡻⣛⣛⢪⠟⣿⣿⣿⣿⢿⣟⣿⠵⣏⣕⡾⢝⡰⢃⢞⠵⢋⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣷\n"
			"⣠⡾⣳⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡸⠄⢿⡐⣿⣿⣿⣯⣻⣿⣷⣾⣿⣿⣿⣿⣿⢯⢞⡱⡢⣟⣵⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
			"⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⠘⡧⢸⣿⣿⣻⢷⣻⣿⣿⣿⣿⣿⣟⠕⣃⣎⣿⣷⣝⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⠀⣧⠄⣿⣿⣿⣿⣷⣹⣿⣿⢟⢛⣤⣾⣿⣿⢼⣿⣿⣿⣷⡚⢝⠛⣛⣛⣛⡻⢿⣿⣿⣿⣿⣿\n"
			"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣻⣿⠀⣿⠒⣿⣿⣿⣿⣿⣷⢻⣿⡿⣿⣿⣿⡿⣿⢻⣿⣿⣿⣿⣿⡘⢷⡹⣿⣿⣿⣷⣝⠻⣿⣿⣿\n"
			"⣿⣽⣟⣿⣽⢿⣯⢿⣻⣿⣿⣿⣿⡼⡟⠄⣿⡁⣿⣿⣿⣿⣿⣿⣿⢟⣭⣭⣿⣿⣟⣿⣼⣿⣿⣿⣿⣿⣷⢺⡅⣿⣿⣿⣿⣿⣟⣬⣛⠿\n"
			"⣟⣾⡿⣽⣾⣿⢯⣿⣿⣿⣿⣿⣿⡗⡇⠂⣿⡁⣿⣿⣿⣿⣿⣿⣿⣯⢽⣿⣿⣿⣻⣏⣿⣿⣿⣿⣿⣿⣿⠚⣇⣸⣿⣿⣿⣿⣿⣾⣿⣿\n";

	printf("%s\n", haru);
	return (haru);
}

char	*detect_built_in(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return ("echo");
	if (ft_strcmp(str, "cd") == 0)
		return ("cd");
	if (ft_strcmp(str, "pwd") == 0)
		return ("pwd");
	if (ft_strcmp(str, "export") == 0)
		return ("export");
	if (ft_strcmp(str, "unset") == 0)
		return ("unset");
	if (ft_strcmp(str, "env") == 0)
		return ("env");
	if (ft_strcmp(str, "exit") == 0)
		return ("exit");
	if (ft_strcmp(str, "haru") == 0)
		return (ft_print_haru());
	return ("nothing");
}

int	detect_pipe(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (1);
	return (0);
}

int	detect_redirections(char *str)
{
	if (ft_strcmp(str, "<") == 0)
		return (1);
	if (ft_strcmp(str, "<<") == 0)
		return (1);
	if (ft_strcmp(str, ">") == 0)
		return (1);
	if (ft_strcmp(str, ">>") == 0)
		return (1);
	return (0);
}

// missing detecting  '$?'
int	detect_env_var(char *str)
{
	if (ft_strcmp(str, "$") == 0)
		return (1);
	return (0);
}

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
// ------------Signals-------------------

void	addto_history(t_manager manager)
{
	if (manager.input && *manager.input) // if is not NULL or empty
		add_history(manager.input);
}

// -------------------------------------

/* t_command *init_cmd(char *command)
{
	t_command *aux;

	aux = calloc(1, sizeof(t_command));
	if (!aux)
		return (NULL); // n ta bem
	aux->cmd = ft_strdup(command); 
	if (!aux->cmd)
	{
		free(aux);
		return (NULL);
	}
	aux->args = ft_split2(aux->cmd, ' ');;
	return (aux);
} */

void addtohistory_andclean(t_manager *manager)
{
    if (manager->input && *manager->input)
        add_history(manager->input);

    if (manager->cmd)
        free_argv(manager->cmd);

    free(manager->input);
    manager->cmd = NULL;
    manager->input = NULL;
}

// -------------------------------------
int	main(void)
{
	static t_manager	manager;
	//static t_command	cmd;
	//void*				lst_aux;
	int					i;
	int 				signal_status;
	//t_list				*cmds;
	//t_list				*current;
	//t_command	*cmd;

	setup_signals();

	//cmds = NULL;
	//i = 0;
	while (manager.signal != SIGINT && manager.signal != SIGQUIT)
	{
		manager.input = readline("🐴");

		signal_status = checkforsignals(&manager);
		if (signal_status == 1)
			break;
		if (signal_status == 2)
			continue;
		printf("finished reading -> %s\n", manager.input);
		if(parcing(&manager) == 1)
		{
			addtohistory_andclean(&manager);
			//printf("\n!!!Syntax Error!!!\n");
			continue;
		}
		printf("\nargv:");
		i = 0;
		while (manager.cmd[i] != NULL)
		{
			//ft_lstadd_back(&cmds, ft_lstnew(init_cmd(manager.cmd[i])));
			printf("\n[%d]%s", i, manager.cmd[i]);
			i++;
		}
		printf("\n");
		/* i = 0;
		current = cmds;

		while (current != NULL)
		{
			cmd = (t_command *)current->content;
			if (cmd && cmd->cmd)
			{
				i = 0;
				printf("Command: (%s)\n", cmd->cmd);
				while (cmd->args && cmd->args[i])
				{
					printf("\targ[%d]: %s\n", i, cmd->args[i]);
					i++;
				}
			}
			current = current->next;
		} */
		addtohistory_andclean(&manager);
	}
	rl_clear_history();
	return (0);
}
