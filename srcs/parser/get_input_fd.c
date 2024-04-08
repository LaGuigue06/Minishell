/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:25:56 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/12 14:23:26 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_input_fd(t_data *data, t_lexer *lexer)
{
	t_lexer	*head;
	int		input_fd;

	head = lexer;
	while (head->prev && head->prev->token != PIPE)
		head = head->prev;
	while (head->next && head->next->token != PIPE)
	{
		if (head->token == ONE_LEFT)
		{
			input_fd = open(head->next->word, O_RDONLY, 0777);
			if (input_fd == -1)
				error(head->next->word, 1, data);
			return (input_fd);
		}
		head = head->next;
	}
	return (0);
}
