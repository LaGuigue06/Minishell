/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:42:15 by laguigue          #+#    #+#             */
/*   Updated: 2024/04/21 17:56:23 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	get_size(t_data *data, t_lexer *lexer, char *cmd)
{
	t_lexer	*head;
	char	*temp;
	size_t	size;

	size = 0;
	temp = NULL;
	head = lexer;
	while (head->prev && head->prev->token != PIPE)
		head = head->prev;
	while (head)
	{
		temp = expander(data, head->word);
		if (ft_strcmp(temp, cmd) == 0)
			break ;
		head = head->next;
	}
	if (temp != NULL)
		free(temp);
	while (head && head->token == WORD)
	{
		++size;
		head = head->next;
	}
	return (size);
}

static char	*save_line(char **result)
{
	free_arr(result);
	return (NULL);
}

char	**get_args2(t_data *data, t_lexer *head, char *cmd, char **result)
{
	size_t	index;
	char	*temp;

	index = 0;
	temp = NULL;
	while (head->prev && head->prev->token != PIPE)
		head = head->prev;
	while (head)
	{
		temp = expander(data, head->word);
		if (ft_strcmp(temp, cmd) == 0)
			break ;
		head = head->next;
	}
	if (temp != NULL)
		free(temp);
	while (head && head->token == WORD)
	{
		result[index++] = expander(data, head->word);
		if (result[index - 1] == NULL)
			save_line(result);
		head = head->next;
	}
	result[index] = NULL;
	return (result);
}

char	**get_args(t_data *data, t_lexer *lexer, char *cmd)
{
	char	**result;
	t_lexer	*head;

	if (cmd == NULL)
		return (NULL);
	result = ft_calloc(sizeof(char *), get_size(data, lexer, cmd) + 1);
	if (result == NULL)
		return (NULL);
	head = lexer;
	return (get_args2(data, head, cmd, result));
}
