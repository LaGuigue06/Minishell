/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:25:52 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/05 18:42:19 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"
#include "../../includes/minishell.h"

static char	**ft_arrdup(char **arr)
{
	size_t	index;
	char	**result;

	index = 0;
	while (arr[index])
		++index;
	result = ft_calloc(sizeof(char *), index + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (arr[index])
	{
		result[index] = ft_strdup(arr[index]);
		if (result[index] == NULL)
		{
			ft_free_tab(result);
			return (NULL);
		}
		++index;
	}
	result[index] = NULL;
	return (result);
}

static void	get_pwd(t_data *data)
{
	size_t	index;

	index = 0;
	while (data->env[index])
	{
		if (find_path(data->env[index], "PWD="))
			data->pwd = data->env[index];
		else if (find_path(data->env[index], "OLDPWD="))
			data->old_pwd =data->env[index];
		++index;
	}
}

t_data	*init_value(char **env)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (NULL);
	data->env = ft_arrdup(env);
	if (data->env == NULL)
		return (NULL);
	data->path = get_path(env);
	get_pwd(data);
	data->cmd = NULL;
}
