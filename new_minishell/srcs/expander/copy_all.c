/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:32:34 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/17 16:03:02 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	copy_variable(t_data *data, char *result, char *variable, size_t *index_result)
{
	size_t	env_index;
	size_t	index;
	int		was_found;

	env_index = 0;
	index = 0;
	was_found = 0;
	while (data->env[env_index])
	{
		if (expander_cmp(variable, data->env[env_index]) == 0)
		{
			was_found = 1;
			break ;
		}
		++env_index;
	}
	if (!was_found)
		return ;
	while (data->env[env_index][index] && data->env[env_index][index] != '=')
		++index;
	++index;
	while (data->env[env_index][index])
	{
		result[*index_result] = data->env[env_index][index];
		++(*index_result);
		++index;
	}
	result[*index_result] = '\0';
}

void	copy_all(t_data *data, char *result, char *str, char **variable)
{
	char	stop;
	size_t	index_result;
	size_t	index_variable;
	size_t	index;

	stop = '\0';
	index = 0;
	index_result = 0;
	index_variable = 0;
	while (str[index])
	{
		if ((str[index] == 34 || str[index] == 39) && stop == '\0')
			stop = str[index++];
		if (str[index] && str[index] == stop)
		{
			++index;
			stop = '\0';
		}
		if (str[index] && str[index] == '$' && stop != 39)
		{
			copy_variable(data, result, variable[index_variable++], &index_result);
			while (str[index] && str[index] != ' ' && str[index] != 34 && str[index] != 39)
				++index;
		}
		if (str[index])
		{
			if (str[index] != stop)
				result[index_result++] = str[index];
			++index;
		}
	}
	result[index_result] = '\0';
}
