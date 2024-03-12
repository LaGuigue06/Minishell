/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:45:56 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/11 17:13:01 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lexer(t_data *data)
{
	char	**all_word;
	size_t	index;

	parse_quote(data);						
	all_word = lexer_split(data->line);		// MUST DO A SPECIAL SPLIT FOR IT !!!!
	if (all_word == NULL)
		return (error(MALLOC_ERROR, 0, data));
	index = 0;
	while (all_word[index])
	{
		if (ft_strcmp(all_word[index], "|") == 0)
			++data->pipe_count;
		if (!lexer_add(&data->lexer, all_word[index]))
		{
			free_arr(all_word);
			return (error(MALLOC_ERROR, 0, data));
		}
		++index;
	}
	free_arr(all_word);
	check_token(data);
}
