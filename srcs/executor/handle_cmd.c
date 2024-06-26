/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:44:29 by guillaumero       #+#    #+#             */
/*   Updated: 2024/05/13 19:30:30 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_absolute_path(t_parser *parser)
{
	if (access(parser->cmd, X_OK | F_OK) != 0)
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd(parser->cmd, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit(127);
	}
	return (ft_strdup(parser->cmd));
}

void	handle_cmd(t_data *data, t_parser *parser)
{
	char	*binary;

	check_redirection(parser);
	if (parser->builtin)
	{
		execute_builtin(parser, data);
		exit(0);
	}
	if (!data->path)
	{
		ft_putstr_fd("Minishell: PATH not set\n", STDERR_FILENO);
		exit(1);
	}
	binary = get_binary(data->path, parser->cmd);
	if (binary == NULL)
		binary = get_absolute_path(parser);
	if (execve(binary, parser->args, data->env) == -1)
	{
		write(STDERR_FILENO, "Minishell: ", 11);
		perror(binary);
		free(binary);
		exit(127);
	}
}
