/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vampaier2 <vampaier2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:30:58 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/07 11:41:40 by vampaier2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"




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

void free_cmds(void *ptr)
{
    t_args *args;

    if (!ptr)
        return;
    args = (t_args *)ptr;
    if (args->content)
	{
        free(args->content);
	}
	if (args->type)
	{
		free(args->type);
	}
    // Don't free args->type - it points to string literals like "pipe", "arg"
    free(args);
}

void	print_valueandtype(t_list *cmds)
{
	t_list	*current;
	t_args	*cmd;

	current = cmds;
	while (current != NULL)
	{
		cmd = (t_args *)current->content;
		if (cmd && cmd->content)
		{
			printf("Content: (%s)\n", cmd->content);
			printf("\tType: (%s)\n", cmd->type);
		}
		current = current->next;
	}
}

void	print_value(t_list *cmds)
{
	t_list	*current;
	t_args	*cmd;

	current = cmds;
	while (current != NULL)
	{
		cmd = (t_args *)current->content;
		if (cmd && cmd->content)
		{
			printf("%s", cmd->content);
		}
		current = current->next;
	}
	printf("\n");
}

// -------------------------------------
int	main(void)
{
	static t_manager	manager;
	//int					i;
	int 				signal_status;

	setup_signals();
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
			continue;
		}
		print_valueandtype(manager.cmds);
		print_value(manager.cmds);
		addtohistory_andclean(&manager);
	}
	//FREE LINKED cdLIST
	free_cmds((t_args *)manager.cmds); // acho que n está a dar free corretamente
	rl_clear_history();
	return (0);
}
