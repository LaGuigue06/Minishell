/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:54:35 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/12 11:15:55 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_cmd(t_lexer *lexer)
{
	t_lexer	*head;

	head = lexer;
	while (head->prev && head->prev->token != PIPE)
		head = head->prev;
	if (head->token == 3 || head->token == 4 || head->token == 5 || head->token == 6)
	{
		while (head->next->next && head->next->next->token != PIPE)
		{
			head = head->next->next;
			if (head->token == WORD)
				break ;
		}
	}
	if (head->token == 3 || head->token == 4 || head->token == 5 || head->token == 6)
		return (NULL);
	return (ft_strtrim_cmd(head->word));
}
