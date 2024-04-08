/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:46:28 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/22 18:18:24 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	add_pipe(t_data *data, size_t *index)
{
	if (data->line[*index + 1] == '|')
	{
		if (lexer_add(&data->lexer, "||", PIPE_PROMP, 0) == 0)
			error(MALLOC_ERROR, 0, data);
		*index = *index + 2;
	}
	else
	{
		if (lexer_add(&data->lexer, "|", PIPE, 0) == 0)
			error(MALLOC_ERROR, 0, data);
		++(*index);
		++data->pipe_count;
	}
}

static void	add_right(t_data *data, size_t *index)
{
	if (data->line[*index + 1] == '>')
	{
		if (lexer_add(&data->lexer, ">>", TWO_RIGHT, 0) == 0)
			error(MALLOC_ERROR, 0, data);
		*index = *index + 2;
	}
	else
	{
		if (lexer_add(&data->lexer, ">", ONE_RIGHT, 0) == 0)
			error(MALLOC_ERROR, 0, data);
		++(*index);
	}
}

static void	add_left(t_data *data, size_t *index)
{
	if (data->line[*index + 1] == '<')
	{
		if (lexer_add(&data->lexer, "<<", TWO_LEFT, 0) == 0)
			error(MALLOC_ERROR, 0, data);
		*index = *index + 2;
	}
	else
	{
		if (lexer_add(&data->lexer, "<", ONE_LEFT, 0) == 0)
			error(MALLOC_ERROR, 0, data);
		++(*index);
	}
}

void	add_token(t_data *data, size_t *index)
{
	if (data->line[*index] == '|')
		add_pipe(data, index);
	else if (data->line[*index] == '>')
		add_right(data, index);
	else if (data->line[*index] == '<')
		add_left(data, index);
	else if (data->line[*index] == ';')
		error(SEMICOLON_TOKEN, 0, data);
}
