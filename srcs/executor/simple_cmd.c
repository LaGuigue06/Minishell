/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:26:11 by guillaumero       #+#    #+#             */
/*   Updated: 2024/05/13 19:29:18 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	simple_cmd(t_data *data, t_parser *parser)
{
	int	pid;
	int	status;

	check_heredoc(data, parser);
	if (ft_strcmp(parser->cmd, "exit") == 0
		|| ft_strcmp(parser->cmd, "unset") == 0
		|| ft_strcmp(parser->cmd, "export") == 0
		|| ft_strcmp(parser->cmd, "cd") == 0)
	{
		execute_builtin(parser, data);
		g_pid = 0;
		return (1);
	}
	pid = fork();
	if (pid == -1)
		error("fork", 1, data);
	if (pid == 0)
		handle_cmd(data, parser);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_pid = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}
