/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:22:06 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/22 18:17:24 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_token(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == ';')
		return (1);
	return (0);
}

static void	skip_space(char *line, size_t *index)
{
	while (line[*index] && (line[*index] == ' '
			|| (line[*index] >= 9 && line[*index] <= 13)))
		++(*index);
}

void	get_lexer(t_data *data)
{
	size_t	index;

	index = 0;
	while (data->line[index])
	{
		skip_space(data->line, &index);
		if (is_token(data->line[index]))
			add_token(data, &index);
		else
			add_word(data, &index);
	}
}
