/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_executor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:22:58 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/22 19:58:39 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(t_parser *parser, t_data *data)
{
	int	output_fd;

	output_fd = 1;
	if (ft_strcmp(parser->cmd, "echo") == 0)
		return (execute_echo(parser->args + 1));
	if (ft_strcmp(parser->cmd, "env") == 0)
		return (execute_env(data->env, output_fd));
	if (ft_strcmp(parser->cmd, "pwd") == 0)
		return (execute_pwd(data, parser->output_fd));
	if (ft_strcmp(parser->cmd, "exit") == 0)
	{
		free_data(data);
		exit(EXIT_SUCCESS);
	}
	if (ft_strcmp(parser->cmd, "cd") == 0)
		return (execute_cd(data, parser->args + 1));
	if (ft_strcmp(parser->cmd, "export") == 0)
		return (execute_export(data, parser->args, parser->output_fd));
	if (ft_strcmp(parser->cmd, "unset") == 0)
		return (execute_unset(data, parser->args, parser->output_fd));
	return (0);
}
