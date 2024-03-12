/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:42:15 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/11 18:51:12 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	get_size(t_lexer *lexer, char *cmd)
{
	t_lexer	*head;

	head = lexer;
	while (head->prev)
	{
		if (!ft_strcmp(head->word, cmd))
	}

}

char	**get_args(t_lexer *lexer, char *cmd)
{
	size_t	index;
	char	**result;
	t_lexer	*head;

	if (cmd == NULL)
		return (NULL);
	result = ft_calloc(sizeof(char *), get_size() + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	head = lexer;
	while (index < get_size())
	{
		result[index++] = ft_strdup(head->word);
		if (result[index - 1] == NULL)
		{
			free_arr(result);
			return (NULL);
		}
	}
	result[index] = NULL;
	return (result);
}
