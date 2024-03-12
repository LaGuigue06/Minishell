/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:59:04 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/05 18:41:57 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char	*line;

	if (argc > 1)
		return (EXIT_FAILURE);
	data = init_value(env);
	using_history();
	while (1)
	{
		line = readline(GREEN"Minishell "RED">> " RESET);
		if (line == NULL)
			break ;
		//data = init_command(line, NULL);
		add_history(line);
		//print_command(cmd);
		free(line);
		//suite = parse_suite(line); // todo parse() = parse_suite(), parse_suite(), ...
		//cmd = parse(line);
		//ft_execute(cmd, env);
	}
	return (0);
}