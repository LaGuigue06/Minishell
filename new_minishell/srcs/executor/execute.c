/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumeroustan <guillaumeroustan@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:20:16 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/18 16:11:18 by guillaumero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	forking(t_data *data, t_parser *parser, int *fd_pipe, int fd_in, bool is_new)
{
	static int	i = 0;

	if (is_new == 1)
	{
		i = 0;
		is_new = 0;
	}
	data->pid[i] = fork();
	if (data->pid[i] == -1)
		error("fork", 1, data);
	if (data->pid[i] == 0)
	{
		if (parser->prev)
			dup2(fd_in, STDIN_FILENO);
		if (parser->next)
			dup2(fd_pipe[1], STDOUT_FILENO);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		if (parser->prev)
			close(fd_in);
		handle_cmd(data, parser);
	}
	++i;
}

void	wait_all(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->pipe_count)
	{
		waitpid(data->pid[i], &status, 0);
		++i;
	}
	waitpid(data->pid[i], &status, 0);
}

int execute(t_data *data)
{
	t_parser	*head;
	int			fd_pipe[2];
	int			fd_in;
	int			is_new;

	fd_in = STDIN_FILENO;
	head = data->parser;
	is_new = 1;
	if (data->pipe_count == 0)
		return (simple_cmd(data, head));
	data->pid = ft_calloc(sizeof(int), data->pipe_count + 2);
	if (data->pid == NULL)
		error(MALLOC_ERROR, 0, data);
	while (head)
	{
		if (head->next)
			if (pipe(fd_pipe) == -1)
				error(PIPE_ERROR, 1, data);
		forking(data, head, fd_pipe, fd_in, is_new);
		close(fd_pipe[1]);
		if (head->prev)
			close(fd_in);
		fd_in = fd_pipe[0];
		head = head->next;
	}
	wait_all(data);
	return (1);
}