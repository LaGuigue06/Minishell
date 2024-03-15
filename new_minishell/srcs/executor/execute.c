/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:20:16 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/13 17:46:01 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int execute(t_data *data)
{
	t_parser	*head;

	head = data->parser;
	while (head)
	{
		if (data->pipe_count == 0)
			return (simple_cmd(data, head));
		/*else
			to_do();*/
		head = head->next;
	}
	return (1);
}