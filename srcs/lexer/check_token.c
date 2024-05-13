/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:05:38 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/23 18:50:19 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_correct_token(t_data *data, t_lexer *head)
{
	if (head->token == PIPE)
		return (error(PIPE_SYNTAX_ERROR, 0, data));
	else if (head->token == ONE_RIGHT)
		return (error(ONE_RIGHT_SYNTAX_ERROR, 0, data));
	else if (head->token == TWO_RIGHT)
		return (error(TWO_RIGHT_SYNTAX_ERROR, 0, data));
	else if (head->token == ONE_LEFT)
		return (error(ONE_LEFT_SYNTAX_ERROR, 0, data));
	else if (head->token == TWO_LEFT)
		return (error(TWO_LEFT_SYNTAX_ERROR, 0, data));
}

void	check_token(t_data *data)
{
	t_lexer	*head;

	head = data->lexer;
	while (head->next)
	{
		if (head->token == BACKSLASH)
			return (error(BACKSLASH_TOKEN, 0, data));
		else if (head->token == SEMICOLON)
			return (error(BACKSLASH_TOKEN, 0, data));
		else if (head->token == PIPE_PROMP)
			return (error(PIPE_PROMP_TOKEN, 0, data));
		else if (head->token != WORD && head->next->token != WORD)
			return (print_correct_token(data, head->next));
		else if (head->token == PIPE && head->prev == NULL)
			return (error(PIPE_SYNTAX_ERROR, 0, data));
		head = head->next;
	}
	if (head->token != WORD)
		return (error(NEWLINE_SYNTAX_ERROR, 0, data));
}
