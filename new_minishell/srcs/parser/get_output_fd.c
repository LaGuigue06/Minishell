/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:26:41 by gurousta          #+#    #+#             */
/*   Updated: 2024/04/04 16:46:41 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_output_fd(t_data *data, t_lexer *lexer)
{
	t_lexer	*head;
	int		o_fd;

	head = lexer;
	while (head->prev && head->prev->token != PIPE)
		head = head->prev;
	while (head->next && head->next->token != PIPE)
	{
		if (head->token == ONE_RIGHT)
		{
			o_fd = open(head->next->word, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (o_fd == -1)
				error(head->next->word, 1, data);
			return (o_fd);
		}
		if (head->token == TWO_RIGHT)
		{
			o_fd = open(head->next->word, O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (o_fd == -1)
				error(head->next->word, 1, data);
			return (o_fd);
		}
		head = head->next;
	}
	return (1);
}
