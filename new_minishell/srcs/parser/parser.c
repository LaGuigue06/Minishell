/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:28:31 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/11 18:39:59 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parser(t_data *data)
{
	t_lexer	*head;

	head = data->lexer;
	while (head->next)
	{
		if (head->token == PIPE)
			if (parser_add(&data->parser, head) == 0)
				return (error(MISSIMG_COMMAND, 0, data));
		head = head->next;
	}
	if (parser_add(&data->parser, head) == 0)
		return (error(MISSIMG_COMMAND, 0, data));
}
