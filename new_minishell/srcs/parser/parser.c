/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:28:31 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/12 16:01:50 by vicalvez         ###   ########.fr       */
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
			if (parser_add(&data->parser, head, data) == 0)
				return (error(MISSIMG_COMMAND, 0, data));
		head = head->next;
	}
	if (parser_add(&data->parser, head, data) == 0)
		return (error(MISSIMG_COMMAND, 0, data));
}
