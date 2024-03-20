/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumeroustan <guillaumeroustan@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:44:29 by guillaumero       #+#    #+#             */
/*   Updated: 2024/03/18 12:44:46 by guillaumero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_cmd(t_data *data, t_parser *parser)
{
	char	*binary;
	
	binary = get_binary(data->path, parser->cmd);
	if (binary == NULL)
		binary = ft_strdup(parser->cmd);
	if (execve(binary, parser->args, data->env) == -1)
	{
		write(STDERR_FILENO, "Minishell: ", 11);
		perror(binary);
		free(binary);
		exit(1);
	}
}
