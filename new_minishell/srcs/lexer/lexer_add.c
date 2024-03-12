/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:13:10 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/07 15:47:55 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer_add(t_lexer **lexer, char *word)
{
	t_lexer	*head;

	if (*lexer == NULL)
	{
		*lexer = lexer_new(word, NULL);
		if (*lexer == NULL)
			return (0);
		return (1);
	}
	head = *lexer;
	while (head->next)
		head = head->next;
	head->next = lexer_new(word, head);
	if (head->next == NULL)
		return (0);
	return (1);
}
