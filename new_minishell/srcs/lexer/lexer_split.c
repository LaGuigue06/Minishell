/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:34:51 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/09 19:18:18 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	count_words(char *line)
{
	size_t	index;
	size_t	words;
	char	stop;

	index = 0;
	words = 0;
	while (line[index])
	{
		stop = ' ';
		if (line[index] != ' ')
		{
			++words;
			if (line[index] == 34 || line[index] == 39)
				stop = line[index++];
			if ((stop == 34 || stop == 39) && line[index] == stop && (line[index + 1] == '\0' || line[index + 1] == ' '))
				stop = ' ';
			while (line[index] && line[index] != stop)
			{
				++index;
				if (line[index] && line[index] == stop && line[index + 1] && (line[index + 1] == 34 || line[index + 1] == 39))
				{
					if (stop == ' ')
						break ;
					stop = line[++index];
					++index;
				}
				else if (line[index] && stop == ' ' && (line[index + 1] == 34 || line[index + 1] == 39))
					stop = line[index++];
				else if (line[index] && line[index] == stop && line[index + 1] != '\0' && line[index+ 1] != ' ')
					stop = ' ';
				else if (line[index] && line[index] == stop && (line[index + 1] == '\0' || line[index + 1] == ' '))
				{
					if (stop == 34 || stop == 39)
						++index;
					break ;
				}
			}
		}
		else
			++index;
	}
	return (words);
}

static char	*strdup_lexer(char *line, char stop)
{
	size_t	index;
	char	*result;

	stop = ' ';
	index = 0;
	if (line[index] == 34 || line[index] == 39)
		stop = line[index++];
	if ((stop == 34 || stop == 39) && line[index] == stop && (line[index + 1] == '\0' || line[index + 1] == ' '))
		stop = ' ';
	while (line[index] && line[index] != stop)
	{
		++index;
		if (line[index] && line[index] == stop && line[index + 1] && (line[index + 1] == 34 || line[index + 1] == 39))
		{
			if (stop == ' ')
				break ;
			stop = line[++index];
			++index;
		}
		else if (line[index] && line[index] == stop && line[index + 1] != '\0' && line[index+ 1] != ' ')
			stop = ' ';
		else if (line[index] && line[index] == stop && (line[index + 1] == '\0' || line[index + 1] == ' '))
		{
			if (stop == 34 || stop == 39)
				++index;
			break ;
		}
	}
	result = ft_calloc(sizeof(char), index + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	if (line[index] == 34 || line[index] == 39)
	{
		stop = line[index];
		result[index] = line[index];
		++index;
	}
	if ((stop == 34 || stop == 39) && line[index] == stop && (line[index + 1] == '\0' || line[index + 1] == ' '))
		stop = ' ';
	while (line[index] && line[index] != stop)
	{
		result[index] = line[index];
		++index;
		if (line[index] && line[index] == stop && line[index + 1] && (line[index + 1] == 34 || line[index + 1] == 39))
		{
			if (stop == ' ')
				break ;
			result[index] = line[index];
			stop = line[++index];
			result[index] = line[index];
			++index;
		}
		else if (line[index] && line[index] == stop && line[index + 1] != '\0' && line[index+ 1] != ' ')
			stop = ' ';
		else if (line[index] && line[index] == stop && (line[index + 1] == '\0' || line[index + 1] == ' '))
		{
			if (stop == 34 || stop == 39)
			{
				result[index] = line[index];
				++index;
			}
			break ;
		}
	}
	result[index] = '\0';
	return (result);
}

char	**lexer_split(char *line)
{
	char	**result;
	char	stop;
	size_t	index;
	size_t	index_result;

	index = 0;
	index_result = 0;
	result = ft_calloc(sizeof(char *), count_words(line) + 1);
	if (result == NULL)
		return (NULL);
	while (line[index])
	{
		stop = ' ';
		if (line[index] != ' ')
		{
			result[index_result++] = strdup_lexer(line + index, line[index]);
			if (result[index_result - 1] == NULL)
			{
				free_arr(result);
				return (NULL);
			}
			if (line[index] == 34 || line[index] == 39)
				stop = line[index++];
			if ((stop == 34 || stop == 39) && line[index] == stop && (line[index + 1] == '\0' || line[index + 1] == ' '))
				stop = ' ';
			while (line[index] && line[index] != stop)
			{
				++index;
				if (line[index] && line[index] == stop && line[index + 1] && (line[index + 1] == 34 || line[index + 1] == 39))
				{
					if (stop == ' ')
						break ;
					stop = line[++index];
					++index;
				}
				else if (line[index] && line[index] == stop && line[index + 1] != '\0' && line[index+ 1] != ' ')
					stop = ' ';
				else if (line[index] && line[index] == stop && (line[index + 1] == '\0' || line[index + 1] == ' '))
				{
					++index;
					break ;
				}
			}
		}
		else
			++index;
	}
	result[index_result] = NULL;
	return (result);
}
