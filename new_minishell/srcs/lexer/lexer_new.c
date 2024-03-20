/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumeroustan <guillaumeroustan@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:59:15 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/18 10:45:37 by guillaumero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_token(char *word)
{
	if (ft_strcmp(word, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(word, ">") == 0)
		return (ONE_RIGHT);
	else if (ft_strcmp(word, ">>") == 0)
		return (TWO_RIGHT);
	else if (ft_strcmp(word, "<") == 0)
		return (ONE_LEFT);
	else if (ft_strcmp(word, "<<") == 0)
		return (TWO_LEFT);
	else if (ft_strcmp(word, "\\" + 1) == 0)
		return (BACKSLASH);
	else if (ft_strcmp(word, ";") == 0)
		return (SEMICOLON);
	else if (ft_strcmp(word, "||") == 0)
		return (PIPE_PROMP);
	return (WORD);
}

t_lexer	*lexer_new(char *word, t_lexer *prev)
{
	t_lexer	*new_lexer;

	new_lexer = ft_calloc(sizeof(t_lexer), 1);
	if (new_lexer == NULL)
		return (NULL);
	new_lexer->word = NULL;
	new_lexer->word = ft_strdup(word);
	if (new_lexer->word == NULL)
		return (NULL);
	new_lexer->token = get_token(word);
	new_lexer->next = NULL;
	new_lexer->prev = prev;
	return (new_lexer);
}
