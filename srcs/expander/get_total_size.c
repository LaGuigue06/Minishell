/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_total_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:06:51 by gurousta          #+#    #+#             */
/*   Updated: 2024/05/13 18:33:41 by laguigue         ###   ########.fr       */
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
		if (ft_strchr(variable[index], '=') == NULL)
			size = size + ft_strlen(variable[index]);
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
		if (str[index] && str[index] == '$' && stop != 39 && str[index + 1] != ' ' && str[index + 1] != '\0')
		{
			++index;
			while (str[index] && !expander_stop(str[index]))
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
