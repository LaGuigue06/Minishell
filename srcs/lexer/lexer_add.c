/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:13:10 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/22 14:54:00 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer_add(t_lexer **lexer, char *word, int token, bool free_word)
{
	t_lexer	*head;

	if (*lexer == NULL)
	{
		*lexer = lexer_new(word, token, NULL, free_word);
		if (*lexer == NULL)
			return (0);
		return (1);
	}
	head = *lexer;
	while (head->next)
		head = head->next;
	head->next = lexer_new(word, token, head, free_word);
	if (head->next == NULL)
		return (0);
	return (1);
}
