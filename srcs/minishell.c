/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumeroustan <guillaumeroustan@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:48:39 by laguigue          #+#    #+#             */
/*   Updated: 2024/05/13 14:36:36 by guillaumero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "minisig.h"

int	g_pid;

void	reset_data(t_data *data)
{
	free_data(data);
	if (data->line != NULL)
		free(data->line);
	if (data->pid != NULL)
		free(data->pid);
	data->pid = NULL;
	data->line = NULL;
	data->pipe_count = 0;
	data->is_new = 1;
	minishell(data);
}

void	minishell(t_data *data)
{
	data->line = readline(GREEN"Mnishell "RED">> " RESET);
	if (data->line == NULL || data->line[0] == '\0')
		reset_data(data);
	add_history(data->line);
	lexer(data);
	parser(data);
	execute(data);
	reset_data(data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (!init_value(&data, env, argv, argc))
		return (EXIT_FAILURE);
	using_history();
	minisig_init(&data);
	minishell(&data);
	rl_clear_history();
	free_all(&data);
	return (EXIT_SUCCESS);
}
