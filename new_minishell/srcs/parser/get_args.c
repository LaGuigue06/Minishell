/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:42:15 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/12 15:14:08 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	get_size(t_lexer *lexer, char *cmd)
{
	t_lexer	*head;
	size_t	size;

	head = lexer;
	while (head->prev)
	{
		if (ft_strcmp(head->word, cmd) == 0)
			break ;
		head = head->prev;
	}
	size = 0;
	while (head)
	{
		if (head->token != WORD)
			break ;
		head = head->next;
		++size;
	}
	return (size);
}

char	**get_args2(t_lexer *head, char *cmd, char **result)
{
	size_t	index;

	index = 0;
	while (head->prev)
	{
		if (ft_strcmp(head->word, cmd) == 0 && ft_strcmp(head->prev->word, cmd) != 0)
			break ;
		head = head->prev;
	}
	while (head && head->token != PIPE)
	{
		result[index++] = ft_strdup(head->word);
		if (result[index - 1] == NULL)
		{
			free_arr(result);
			return (NULL);
		}
		head = head->next;
	}
	result[index] = NULL;
	return (result);
}

char	**get_args(t_lexer *lexer, char *cmd)
{
	char	**result;
	t_lexer	*head;

	if (cmd == NULL)
		return (NULL);
	result = ft_calloc(sizeof(char *), get_size(lexer, cmd) + 1);
	if (result == NULL)
		return (NULL);
	head = lexer;
	return (get_args2(head, cmd, result));
}
