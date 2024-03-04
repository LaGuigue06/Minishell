/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:59:04 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 14:45:56 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	//t_list	*cmd;
	//t_suite	*suite;
	t_command *cmd;
	char	*line;
	(void)argc;
	(void)argv;
	(void)env;

	using_history();
	while (1)
	{
		//write(1, "Minishell>>", 12);
		line = readline(GREEN"Minishell "RED">> " RESET);
		//printf("line: %s\n", line);
		cmd = init_command(line, NULL);
		add_history(line);
		print_command(cmd);
		free(line);
		//suite = parse_suite(line); // todo parse() = parse_suite(), parse_suite(), ...
		//cmd = parse(line);
		//ft_execute(cmd, env);
	}
	return (0);
}