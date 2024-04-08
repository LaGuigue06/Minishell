/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_total_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:06:51 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/22 16:34:03 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	size_t	get_env_size(char *env)
{
	size_t	index;
	size_t	size;

	index = 0;
	size = 0;
	while (env[index] && env[index] != '=')
		++index;
	while (env[index])
	{
		++index;
		++size;
	}
	return (size);
}

static size_t	get_size_env(t_data *data, char **variable)
{
	size_t	size;
	size_t	index;
	size_t	env_index;

	index = 0;
	env_index = 0;
	size = 0;
	while (variable[index])
	{
		env_index = 0;
		while (data->env[env_index])
		{
			if (expander_cmp(variable[index], data->env[env_index]) == 0)
			{
				size = size + get_env_size(data->env[env_index]);
				break ;
			}
			++env_index;
		}
		++index;
	}
	return (size);
}

static size_t	get_total_size2(char *str, size_t index, size_t size, char stop)
{
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
			++index;
			while (str[index] && str[index] != ' ' && str[index] != stop
				&& str[index] != 39 && str[index] != '$')
				++index;
		}
		else if (str[index])
		{
			if (str[index] != stop)
				++size;
			++index;
		}
	}
	return (size);
}

size_t	get_total_size(t_data *data, char *str, char **variables)
{
	size_t	size;

	size = get_total_size2(str, 0, 0, '\0');
	return (size + get_size_env(data, variables));
}

/*size_t	get_total_size(t_data *data, char *str, char **variables)
{
	char	stop;
	size_t	index;
	size_t	size;

	index = 0;
	size = 0;
	stop = '\0';
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
			++index;
			while (str[index] && str[index] != ' ' &&
				str[index] != stop && str[index] != 39 && str[index] != '$')
				++index;
		}
		else if (str[index])
		{
			if (str[index] != stop)
				++size;
			++index;
		}			
	}
	return (size + get_size_env(data, variables));
}*/
