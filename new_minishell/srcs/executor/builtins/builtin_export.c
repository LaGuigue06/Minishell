/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:13:22 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/28 15:32:00 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_already_exported(char *str, char **env)
{
	char	*varname;
	char	*env_varname;
	int		i;

	i = 0;
	varname = ft_substr(str, 0, ft_varname_len(str));
	while (env[i])
	{
		env_varname = ft_substr(env[i], 0, ft_varname_len(env[i]));
		if (ft_strcmp(varname, env_varname) == 0)
		{
			free(env_varname);
			free(varname);
			return (1);
		}
		free(env_varname);
		i++;
	}
	free(varname);
	return (0);
}

void	replace_env(char *var, char **env)
{
	char	*varname;
	char	*env_varname;
	int		i;

	varname = ft_substr(var, 0, ft_varname_len(var));
	i = 0;
	while (env[i])
	{
		env_varname = ft_substr(env[i], 0, ft_varname_len(env[i]));
		if (ft_strcmp(env_varname, varname) == 0)
		{
			env[i] = var;
			free(env_varname);
			break ;
		}
		free(env_varname);
		i++;
	}
	free(varname);
}

int	execute_export(t_data *data, char **args, int output_fd)
{
	char	*str;
	char	*tmp;
	char	**new_env;
	int		i;

	if (!args[1])
	{
		execute_env(data->env, output_fd);
		return (1);
	}
	i = 1;
	while (args[i])
	{
		str = ft_strdup(args[i]);
		if (!ft_strchr(str, '='))
		{
			tmp = ft_strdup(str);
			free(str);
			str = ft_strjoin(tmp, "=");
			free(tmp);
		}
		if (is_already_exported(str, data->env))
			replace_env(str, data->env);
		else
		{
			new_env = ft_arrdup(data->env, 1);
			new_env[ft_chararr_size(data->env)] = str;
			free(data->env);
			data->env = new_env;
		}
		i++;
	}
	return (0);
}
