/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:29:17 by vicalvez          #+#    #+#             */
/*   Updated: 2024/05/13 17:05:36 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_unset(t_data *data, char **args, int output_fd)
{
	char	**new_env;
	char	*var_name;
	int		i;

	if (!args[1])
	{
		ft_putstr_fd("unset: not enough arguments\n", output_fd);
		return (1);
	}
	i = 1;
	while (args[i])
	{
		var_name = ft_substr(args[i], 0, ft_varname_len(args[i]));
		if (ft_strcmp("PATH", var_name) == 0)
			data->path = NULL;
		free(var_name);
		new_env = ft_arrdup_exclude(data->env, args[i]);
		free_arr(data->env);
		data->env = new_env;
		i++;
	}
	return (0);
}
