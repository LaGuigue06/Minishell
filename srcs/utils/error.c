/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:23:30 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/22 19:31:27 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error(char *error_msg, bool is_errno, t_data *data)
{
	if (!is_errno)
		ft_putstr_fd(error_msg, STDERR_FILENO);
	else
		perror(error_msg);
	reset_data(data);
}

int	error_pre_loop(char *error_msg, t_data *data)
{
	ft_putstr_fd(error_msg, STDERR_FILENO);
	if (data->env != NULL)
	{
		free_arr(data->env);
		data->env = NULL;
	}
	if (data->path != NULL)
	{
		free_arr(data->path);
		data->path = NULL;
	}
	if (data->old_pwd != NULL)
	{
		free(data->old_pwd);
		data->old_pwd = NULL;
	}
	if (data->pwd != NULL)
	{
		free(data->pwd);
		data->pwd = NULL;
	}
	return (0);
}
