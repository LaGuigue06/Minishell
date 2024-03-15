/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:00:05 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/15 20:13:28 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_current_variable(char *str, char stop)
{
	char	*result;
	size_t	index;

	index = 0;
	while (str[index] && str[index] != ' ' && str[index] != 39 && str[index] != stop)
		++index;
	result = ft_calloc(sizeof(char), index + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != ' ' && str[index] != 39 && str[index] != stop)
	{
		result[index] = str[index];
		++index;
	}
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
		if ((str[index] == 34 || str[index] == 39) && str[index] != stop)
			stop = str[index++];
		if (str[index] && str[index] == stop)
			stop = '\0';
		if (str[index] && str[index] == '$' && stop != 39)
		{
			++count;
			while (str[index] && str[index] != ' ' && str[index] != stop && str[index] != 39)
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
	printf("pour: %s\n", str);
	result = ft_calloc(sizeof(char *), get_variable_number(str));
	printf("nombre de variable: %ld\n", get_variable_number(str));
	if (result == NULL)
		return (NULL);
	while (str[index])
	{
		if (str[index] == 34 || str[index] == 39)
			stop = str[index++];
		if (str[index] && str[index] == stop)
			stop = '\0';
		if (str[index] && str[index] == '$' && stop != 39)
		{
			result[index_result++] = get_current_variable(str + index + 1, stop);
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
