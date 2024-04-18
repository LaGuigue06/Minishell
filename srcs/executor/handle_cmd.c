/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:44:29 by guillaumero       #+#    #+#             */
/*   Updated: 2024/04/17 16:42:18 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	handle_cmd(t_data *data, t_parser *parser)
{
	char	*binary;

	binary = get_binary(data->path, parser->cmd);
	if (binary == NULL)
	{
		if (access(parser->cmd, X_OK | F_OK) != 0)
		{
			ft_putstr_fd("Minishell: ", STDERR_FILENO);
			ft_putstr_fd(parser->cmd, STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(127);
		}
		binary = ft_strdup(parser->cmd);
	}
	if (execve(binary, parser->args, data->env) == -1)
	{
		write(STDERR_FILENO, "Minishell: ", 11);
		perror(binary);
		free(binary);
		exit(1);
	}
}
