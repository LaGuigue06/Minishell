/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:48:03 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/12 14:07:45 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_arr(char **arr)
{
	size_t	index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

void	free_lexer(t_lexer **lexer)
{
	t_lexer	*temp;

	while (*lexer)
	{
		temp = *lexer;
		*lexer = (*lexer)->next;
		if (temp->word != NULL)
		{
			free(temp->word);
			temp->word = NULL;
		}
		free(temp);
		temp = NULL;
	}
	*lexer = NULL;
}

void	free_parser(t_parser **parser)
{
	t_parser	*temp;

	while (*parser)
	{
		temp = *parser;
		*parser = (*parser)->next;
		if (temp->args != NULL)
		{
			free_arr(temp->args);
			temp->args = NULL;
		}
		free(temp);
		temp = NULL;
	}
}

void	free_data(t_data *data)
{
	free_lexer(&data->lexer);
	free_parser(&data->parser);
}

void	free_all(t_data *data)
{
	free_data(data);
	if (data->line != NULL)
		free(data->line);
	if (data->env != NULL)
		free_arr(data->env);
	if (data->path != NULL)
		free_arr(data->path);
}