/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:42:53 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/11 18:43:43 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_builtin(char *word)
{
	if (!ft_strcmp(word, "\"echo\"") || !ft_strcmp(word, "'echo'") || !ft_strcmp(word, "echo"))
		return (ft_strdup("echo"));
	if (!ft_strcmp(word, "\"cd\"") || !ft_strcmp(word, "'cd'") || !ft_strcmp(word, "cd"))
		return (ft_strdup("cd"));
	if (!ft_strcmp(word, "\"pwd\"") || !ft_strcmp(word, "'pwd'") || !ft_strcmp(word, "pwd"))
		return (ft_strdup("pwd"));
	if (!ft_strcmp(word, "\"export\"") || !ft_strcmp(word, "'export'") || !ft_strcmp(word, "export"))
		return (ft_strdup("export"));
	if (!ft_strcmp(word, "\"unset\"") || !ft_strcmp(word, "'unset'") || !ft_strcmp(word, "unset"))
		return (ft_strdup("unset"));
	if (!ft_strcmp(word, "\"env\"") || !ft_strcmp(word, "'env'") || !ft_strcmp(word, "env"))
		return (ft_strdup("env"));
	if (!ft_strcmp(word, "\"exit\"") || !ft_strcmp(word, "'exit'") || !ft_strcmp(word, "exit"))
		return (ft_strdup("exit"));
	return (NULL);
}

t_parser	*parser_new(t_lexer *lexer, t_parser *prev)
{
	t_parser *new;

	new = ft_calloc(sizeof(t_parser), 1);
	if (new == NULL)
		return (NULL);
	new->cmd = get_cmd(lexer);
	new->args = get_args(lexer, new->cmd);
	if (new->args)
	new->next = NULL;
	new->prev = prev;
	return (new);
}
