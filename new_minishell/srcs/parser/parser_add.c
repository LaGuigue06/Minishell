/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:19:52 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/11 16:46:33 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parser_add(t_parser **parser, t_lexer *lexer)
{
	t_parser	*head;

	head = *parser;
	if (*parser == NULL)
	{
		*parser = parser_new(lexer, NULL);
		if (*parser == NULL)
			return (0);
		return (1);
	}
	while (head->next)
		head = head->next;
	head->next = parser_new(lexer, head);
	if (head->next == NULL)
		return (0);
	return (1);
}
