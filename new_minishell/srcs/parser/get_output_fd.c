/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:26:41 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/12 14:20:09 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_output_fd(t_data *data, t_lexer *lexer)
{
	t_lexer	*head;
	int		output_fd;

	head = lexer;
	while (head->prev && head->prev->token != PIPE)
		head = head->prev;
	while (head->next && head->next->token != PIPE)
	{
		if (head->token == ONE_RIGHT)
		{
			output_fd = open(head->next->word, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (output_fd == -1)
				error(head->next->word, 1, data);
			return (output_fd);
		}
		if (head->token == TWO_RIGHT)
		{
			output_fd = open(head->next->word, O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (output_fd == -1)
				error(head->next->word, 1, data);
			return (output_fd);
		}
		head = head->next;
	}
	return (1);
}
