/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:30:45 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/08 20:31:08 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	matching_quote(char *line, size_t *index, char quote)
{
	while (line[++(*index)])
	{
		if (line[*index] == quote)
		{
			++(*index);
			return (1);
		}
	}
	return (0);
}

void	parse_quote(t_data *data)
{
	size_t	index;


	index = 0;
	while (data->line[index])
	{
		if (data->line[index] == 39)
		{
			if (!matching_quote(data->line, &(index), 39))
				return (error(QUOTE_FAIL, 0, data));
		}
		else if (data->line[index] == 34)
		{
			if (!matching_quote(data->line, &index, 34))
				return (error(QUOTE_FAIL, 0, data));
		}
		else
			++index;
	}
}
