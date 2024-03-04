/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:59:04 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 12:59:13 by vicalvez         ###   ########.fr       */
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
		line = readline("Minishell >>");
		//printf("line: %s\n", line);
		add_history(line);
		cmd = init_command(line, NULL);
		free(line);
		print_command(cmd);
		//suite = parse_suite(line); // todo parse() = parse_suite(), parse_suite(), ...
		//cmd = parse(line);
		//ft_execute(cmd, env);
	}
	return (0);
}