/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumeroustan <guillaumeroustan@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:00:05 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/18 17:02:09 by guillaumero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_current_variable(char *str)
{
	char	*result;
	size_t	index;

	index = 0;
	while (str[index] && str[index] != ' ' && str[index] != 39 && str[index] != 34)
		++index;
	result = ft_calloc(sizeof(char), index + 2);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != ' ' && str[index] != 39 && str[index] != 34)
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
		if (str[index] && str[index] == '$' && stop != 39)
		{
			++count;
			while (str[index] && str[index] != ' ' && str[index] != 34 && str[index] != 39)
				++index;
		}
		if (str[index])
			++index;			
	}
	return (count);
}

char	**get_all_variable(char *str)
{
	char	**result;
	char	stop;
	size_t	index;
	size_t	index_result;
	
	index_result = 0;
	index = 0;
	stop = '\0';
	result = ft_calloc(sizeof(char *), get_variable_number(str) + 1);
	if (result == NULL)
		return (NULL);
	while (str[index])
	{
		if ((str[index] == 34 || str[index] == 39) && stop == '\0')
			stop = str[index++];
		if (str[index] && str[index] == stop)
			stop = '\0';
		if (str[index] && str[index] == '$' && stop != 39)
		{
			result[index_result++] = get_current_variable(str + index + 1);
			if (result[index_result - 1] == NULL)
			{
				free_arr(result);
				return (NULL);
			}
			while (str[index] && str[index] != ' ' && str[index] != stop && str[index] != 39)
				++index;
		}
		if (str[index])
			++index;
	}
	result[index_result] = NULL;
	return (result);
}
