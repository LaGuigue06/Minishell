/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumeroustan <guillaumeroustan@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:26:11 by guillaumero       #+#    #+#             */
/*   Updated: 2024/03/18 12:26:33 by guillaumero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	simple_cmd(t_data *data, t_parser *parser)
{
	int	pid;
	int	status;

	if (parser->builtin)
		return (execute_builtin(parser, data));
	pid = fork();
	if (pid == -1)
		error("fork", 1, data);
	if (pid == 0)
		handle_cmd(data, parser);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return(1);
	return (0);
}
