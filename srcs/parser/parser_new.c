/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumeroustan <guillaumeroustan@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:42:53 by laguigue          #+#    #+#             */
/*   Updated: 2024/05/13 14:13:25 by guillaumero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_builtin(char *word)
{
	if (!ft_strcmp(word, "\"echo\"")
		|| !ft_strcmp(word, "'echo'") || !ft_strcmp(word, "echo"))
		return (1);
	if (!ft_strcmp(word, "\"cd\"")
		|| !ft_strcmp(word, "'cd'") || !ft_strcmp(word, "cd"))
		return (1);
	if (!ft_strcmp(word, "\"pwd\"")
		|| !ft_strcmp(word, "'pwd'") || !ft_strcmp(word, "pwd"))
		return (1);
	if (!ft_strcmp(word, "\"export\"")
		|| !ft_strcmp(word, "'export'") || !ft_strcmp(word, "export"))
		return (1);
	if (!ft_strcmp(word, "\"unset\"")
		|| !ft_strcmp(word, "'unset'") || !ft_strcmp(word, "unset"))
		return (1);
	if (!ft_strcmp(word, "\"env\"")
		|| !ft_strcmp(word, "'env'") || !ft_strcmp(word, "env"))
		return (1);
	if (!ft_strcmp(word, "\"exit\"")
		|| !ft_strcmp(word, "'exit'") || !ft_strcmp(word, "exit"))
		return (1);
	return (0);
}

t_parser	*parser_new(t_data *data, t_lexer *lexer, t_parser *prev)
{
	t_parser	*new;

	new = ft_calloc(sizeof(t_parser), 1);
	if (new == NULL)
		return (NULL);
	new->cmd = NULL;
	new->args = NULL;
	new->delimiter = NULL;
	new->redir = NULL;
	new->cmd = get_cmd(lexer, data);
	new->args = get_args(data, lexer, new->cmd);
	new->delimiter = get_delimiter(lexer);
	new->builtin = is_builtin(new->cmd);
	if (new->args == NULL || new->cmd == NULL)
	{
		free_parser(&new);
		return (NULL);
	}
	new->redir = get_redir(data, lexer);
	new->next = NULL;
	new->prev = prev;
	return (new);
}
