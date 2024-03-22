/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:32:34 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/22 17:19:40 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	copy_variable(t_data *data, char *result,
	char *variable, size_t *index_result)
{
	size_t	env_index;
	size_t	index;

	env_index = 0;
	index = 0;
	while (data->env[env_index])
	{
		if (expander_cmp(variable, data->env[env_index]) == 0)
			break ;
		++env_index;
	}
	if (data->env[env_index] == NULL)
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

static void	save_line1(char *str, size_t *index, char *stop)
{
	if ((str[*index] == 34 || str[*index] == 39) && *stop == '\0')
		*stop = str[(*index)++];
	if (str[*index] && str[*index] == *stop)
	{
		++(*index);
		*stop = '\0';
	}
}

static void	save_line2(char *str, size_t *index)
{
	++(*index);
	while (str[*index] && str[*index] != ' '
		&& str[*index] != 34 && str[*index] != 39 && str[*index] != '$')
		++(*index);
}

void	copy_all(t_data *data, char *result, char *str, char **variable)
{
	char	stop;
	size_t	i_result;
	size_t	i_variable;
	size_t	index;

	stop = '\0';
	index = 0;
	i_result = 0;
	i_variable = 0;
	while (str[index])
	{
		save_line1(str, &index, &stop);
		if (str[index] && str[index] == '$' && stop != 39)
		{
			copy_variable(data, result, variable[i_variable++], &i_result);
			save_line2(str, &index);
		}
		else if (str[index])
		{
			if (str[index] != stop)
				result[i_result++] = str[index];
			++index;
		}
	}
	result[i_result] = '\0';
}
