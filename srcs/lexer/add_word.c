/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:07:58 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/22 18:19:20 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	find_quote(t_data *data, size_t *index)
{
	char	quote;

	quote = data->line[(*index)++];
	while (data->line[*index] && data->line[*index] != quote)
		++(*index);
	++(*index);
}

static char	*lexer_dup(t_data *data, size_t starting_index, size_t final_index)
{
	char	*result;
	size_t	index;

	index = 0;
	result = ft_calloc(sizeof(char), final_index - starting_index + 1);
	if (result == NULL)
		error(MALLOC_ERROR, 0, data);
	while (starting_index < final_index)
		result[index++] = data->line[starting_index++];
	result[index] = '\0';
	return (result);
}

void	add_word(t_data *data, size_t *index)
{
	int		starting_index;

	starting_index = *index;
	while (data->line[*index])
	{
		if (data->line[*index] == 34 || data->line[*index] == 39)
			find_quote(data, index);
		else if (is_token(data->line[*index]) || data->line[*index] == ' ')
			break ;
		else if (data->line[*index])
			++(*index);
	}
	lexer_add(&data->lexer, lexer_dup(data, starting_index, *index), WORD, 1);
}
