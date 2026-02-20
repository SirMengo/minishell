/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:30:58 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/20 14:56:35 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* char	*ft_print_haru(void) // maybe think about using a get_next_line?
{
	char	*haru;

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
} */

void	free_cmds(void *ptr)
{
	t_args	*args;

	if (!ptr)
		return ;
	args = (t_args *)ptr;
	if (args->content)
		free_arr(args->content);
	if (args->type)
		free_arr(args->type);
	free(args);
}

void free_env_list(t_list *env_list)
{
	t_list *current = env_list;
	t_list *next;
	t_envar *envar;

	while (current)
	{
		next = current->next;
		envar = (t_envar *)current->content;

		// Free the t_envar struct contents
		if (envar)
		{
			free(envar->key);    // ← Frees the 1,125 bytes
			free(envar->value);  // ← Frees the 3,669 bytes
			free(envar);         // ← Frees the 1,328 bytes
		}
		
		free(current);           // ← Frees the 1,992 bytes (list nodes)
		current = next;
	}
}

int	exec_logic()
{
	data()->cmd = init_arg();
	if (!data()->cmd)
		return (0);
	if (!data()->stop_exec)
		if (!exec_in_parent())
			pipes(data()->cmd);
	data()->stop_exec = false;
	clean_cmd_arr();
	return (1);
}

// -------------------------------------
int	main(int ac, char **av, char **ev)
{

	(void)ac;
	(void)av;
	setup_signals();
	init_env(ev);
	while (data()->manager.signal != SIGINT && data()->manager.signal != SIGQUIT)
	{
		data()->manager.input = readline("minishell: ");
		if (data()->manager.input == NULL)
			break ;
		if (data()->manager.input[0] == '\0')
			continue ;
		if (parcing() == 1)
		{
			cmd_error(2);
			addtohistory_andclean();
			continue ;
		}		
		if (!exec_logic())
			break ;
		addtohistory_andclean();
	}
	rl_clear_history();
	exit_free(data()->err_code);
	return (0);
}
