/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delimiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:39:14 by gurousta          #+#    #+#             */
/*   Updated: 2024/04/21 19:52:55 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_delimiter(t_lexer *lexer)
{
	t_lexer	*head;

	head = lexer;
	while (head->prev && head->prev->token != PIPE)
	{
		if (head->token == TWO_LEFT)
			break ;
		head = head->prev;
	}
	if (head->token == TWO_LEFT)
		return (ft_strdup(head->next->word));
	return (NULL);
}
