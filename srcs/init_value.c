/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:25:17 by laguigue          #+#    #+#             */
/*   Updated: 2024/04/17 16:47:31 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	get_path_pwd_oldpwd(t_data *data)
{
	size_t	index;

	index = 0;
	while (data->env[index])
	{
		if (ft_issubstr(data->env[index], "PATH="))
		{
			data->path = ft_split(data->env[index] + 5, ":");
			if (data->path == NULL)
				return (0);
		}
		else if (ft_issubstr(data->env[index], "PWD="))
			data->pwd = data->env[index] + 4;
		else if (ft_issubstr(data->env[index], "OLDPWD="))
			data->old_pwd = data->env[index] + 7;
		++index;
	}
	if (data->old_pwd == NULL || data->pwd == NULL)
		return (0);
	return (1);
}

int	init_value(t_data *data, char **env, char **argv, int argc)
{
	(void)argv;
	if (argc > 1)
		return (error_pre_loop(NO_ARGUMENT, data));
	data->pipe_count = 0;
	data->line = NULL;
	data->env = NULL;
	data->path = NULL;
	data->pid = NULL;
	g_pid = 0;
	data->env = ft_arrdup(env, 0);
	if (data->env == NULL)
		return (error_pre_loop(MALLOC_ERROR, data));
	if (get_path_pwd_oldpwd(data) == 0)
		return (error_pre_loop(MALLOC_ERROR, data));
	data->lexer = NULL;
	data->parser = NULL;
	return (1);
}
