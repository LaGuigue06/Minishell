/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:32:34 by gurousta          #+#    #+#             */
/*   Updated: 2024/05/13 19:01:57 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	copy_error_number(char *result, char *variable,
	size_t *index_result)
{
	size_t	index;

	index = 0;
	while (variable[index])
		result[(*index_result)++] = variable[index++];
	result[*index_result] = '\0';
}

void	copy_variable(t_data *data, char *result,
	char *variable, size_t *index_result)
{
	size_t	env_index;
	size_t	index;

	env_index = 0;
	index = 0;
	if (ft_strchr(variable, '=') == NULL)
		return (copy_error_number(result, variable, index_result));
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
		save_line1(str, index, stop);
	}
}

static void	save_line2(char *str, size_t *index)
{
	++(*index);
	while (str[*index] && !expander_stop(str[*index]))
		++(*index);
	if (str[*index] == '?' && str[*index - 1] == '$')
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
		if (str[index] && str[index] == '$' && stop != 39
			&& str[index + 1] != ' ' && str[index + 1] != '\0')
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
}
