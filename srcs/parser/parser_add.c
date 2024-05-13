/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:19:52 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/12 13:46:13 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parser_add(t_parser **parser, t_lexer *lexer, t_data *data)
{
	t_parser	*head;

	head = *parser;
	if (*parser == NULL)
	{
		*parser = parser_new(data, lexer, NULL);
		if (*parser == NULL)
			return (0);
		return (1);
	}
	while (head->next)
		head = head->next;
	head->next = parser_new(data, lexer, head);
	if (head->next == NULL)
		return (0);
	return (1);
}
