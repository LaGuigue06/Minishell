/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:56:46 by laguigue          #+#    #+#             */
/*   Updated: 2024/04/21 18:11:37 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_lexer	*get_redir(t_data *data, t_lexer *lexer)
{
	t_lexer	*redir;
	t_lexer	*head;

	head = lexer;
	redir = NULL;
	while (head->prev && head->prev->token != PIPE)
		head = head->prev;
	while (head && head->token != PIPE)
	{
		lexer_add(&redir, head->word, head->token, 0);
		head = head->next;
	}
	return (redir);
}
