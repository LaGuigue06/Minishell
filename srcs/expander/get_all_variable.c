/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:00:05 by gurousta          #+#    #+#             */
/*   Updated: 2024/05/13 19:27:44 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_current_variable(char *str)
{
	char	*result;
	size_t	index;

	index = 0;
	if (str[0] != '\0' && str[0] == '?')
		return (ft_itoa(g_pid));
	while (str[index] && !expander_stop(str[index]))
		++index;
	result = ft_calloc(sizeof(char), index + 2);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (str[index] && !expander_stop(str[index]))
	{
		result[index] = str[index];
		++index;
	}
	result[index++] = '=';
	result[index] = '\0';
	return (result);
}

size_t	get_variable_number(char *str)
{
	char	stop;
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	stop = '\0';
	while (str[index])
	{
		if ((str[index] == 34 || str[index] == 39) && stop == '\0')
			stop = str[index++];
		if (str[index] && str[index] == stop)
			stop = '\0';
		if (str[index] && str[index] == '$' && stop != 39
			&& str[index + 1] != ' ' && str[index + 1] != '\0')
		{
			++count;
			++index;
			while (str[index] && !expander_stop(str[index]))
				++index;
		}
		else if (str[index])
			++index;
	}
	return (count);
}

static void	save_line1(char *str, size_t *index, char *stop)
{
	if ((str[*index] == 34 || str[*index] == 39) && *stop == '\0')
		*stop = str[(*index)++];
	if (str[*index] && str[*index] == *stop)
	{
		++(*index);
		*stop = '\0';
		save_line1(str, index, stop);
	}
}

static void	get_all_variable2(char **result, char *str,
	size_t index, size_t index_result)
{
	char	stop;

	stop = '\0';
	while (str[index])
	{
		save_line1(str, &index, &stop);
		if (str[index] && str[index] == '$' && stop != 39
			&& str[index + 1] != ' ' && str[index + 1] != '\0')
		{
			++index;
			result[index_result++] = get_current_variable(str + index);
			if (result[index_result - 1] == NULL)
			{
				free_arr(result);
				break ;
			}
			while (str[index] && !expander_stop(str[index]))
				++index;
		}
		else if (str[index])
			++index;
	}
}

char	**get_all_variable(char *str)
{
	char	**result;
	size_t	index;
	size_t	index_result;

	index_result = 0;
	index = 0;
	result = ft_calloc(sizeof(char *), get_variable_number(str) + 1);
	if (result == NULL)
		return (NULL);
	get_all_variable2(result, str, index, index_result);
	if (result == NULL)
		return (NULL);
	return (result);
}
