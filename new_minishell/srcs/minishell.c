/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:48:39 by laguigue          #+#    #+#             */
/*   Updated: 2024/04/04 16:49:30 by vicalvez         ###   ########.fr       */
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
	data->line = NULL;
}

void	minishell(t_data *data)
{
	data->line = readline(GREEN"Mnishell "RED">> " RESET);
	if (data->line == NULL || data->line[0] == '\0')
		return ;
	add_history(data->line);
	lexer(data);
	parser(data);
	execute(data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (!init_value(&data, env, argv, argc))
		return (EXIT_FAILURE);
	using_history();
	minisig_init(&data);
	while (1)
	{
		g_pid = 0;
		minishell(&data);
		reset_data(&data);
	}
	rl_clear_history();
	free_all(&data);
	return (EXIT_SUCCESS);
}
