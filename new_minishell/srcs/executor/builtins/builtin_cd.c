/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:41:34 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/28 15:42:29 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_oldpwd(t_data *data)
{
	size_t	index;
	char	*oldpwd;

	index = 0;
	while (data->env[index])
	{
		oldpwd = data->env[index];
		if (expander_cmp("PWD=", data->env[index]) == 0)
			return (ft_substr(oldpwd, ft_varname_len(oldpwd) + 1, ft_strlen(oldpwd)));
		++index;
	}
	return (NULL);
}

static void	update_env(t_data *data)
{
	char	**temp_env;
	char	*temp_pwd;
	char	*temp_opwd;
	size_t	index;

	index = 0;
	while (data->env[index])
		++index;
	temp_env = ft_calloc(sizeof(char *), index + 1);
	temp_pwd = getcwd(NULL, 0);
	temp_opwd = get_oldpwd(data);
	index = 0;
	while (data->env[index])
	{
		if (expander_cmp("PWD=", data->env[index]) == 0)
			temp_env[index] = ft_strjoin("PWD=", temp_pwd);
		else if (expander_cmp("OLDPWD=", data->env[index]) == 0)
			temp_env[index] = ft_strjoin("OLDPWD=", temp_opwd);
		else
			temp_env[index] = ft_strdup(data->env[index]);
		++index;
	}
	temp_env[index] = NULL;
	free_arr(data->env);
	data->env = temp_env;
	data->pwd = temp_pwd;
	data->old_pwd = temp_opwd;
}

static int	print_error(char *cmd)
{
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(cmd, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}

static char	*find_home(t_data *data)
{
	size_t	index;

	index = 0;
	while (data->env[index])
	{
		if (expander_cmp("HOME=", data->env[index]) == 0)
			return (data->env[index] + 5);
		++index;
	}
	return (NULL);
}

int	execute_cd(t_data *data, char **args)
{
	char	*home_path;

	if (*args == NULL || ft_strcmp(args[0], "~") == 0)
	{
		home_path = find_home(data);
		if (home_path == NULL || home_path[0] == '\0')
		{
			ft_putstr_fd("Minishell: HOME is empty or undefined", STDERR_FILENO);
			return (0);
		}
		if (chdir(find_home(data)) == -1)
			return(print_error(args[0]));
	}
	else if (chdir(args[0]) == -1)
		return (print_error(args[0]));
	/*free(data->old_pwd);
	data->old_pwd = ft_strdup(data->pwd);
	free(data->pwd);
	data->pwd = getcwd(NULL, 0);*/
	update_env(data);
	return (0);
}

/*int	execute_cd(t_data *data, char **args)
{
	if (!args[1])
	{
		chdir("~");
		data->old_pwd = data->pwd;
		data->pwd = getenv("HOME");
		return (0);
	}
	if (chdir(args[1]) == -1)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(args[1], 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	data->old_pwd = data->pwd;
	data->pwd = getcwd(NULL, 0);
	return (0);
}*/
