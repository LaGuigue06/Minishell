/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:59:15 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/22 14:53:36 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_lexer	*lexer_new(char *word, int token, t_lexer *prev, bool free_word)
{
	t_lexer	*new_lexer;

	new_lexer = ft_calloc(sizeof(t_lexer), 1);
	if (new_lexer == NULL)
		return (NULL);
	new_lexer->word = NULL;
	new_lexer->word = ft_strdup(word);
	if (free_word)
		free(word);
	if (new_lexer->word == NULL)
		return (NULL);
	new_lexer->token = token;
	new_lexer->next = NULL;
	new_lexer->prev = prev;
	return (new_lexer);
}
