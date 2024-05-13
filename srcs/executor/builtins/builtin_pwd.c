/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:14 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/28 15:41:14 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pwd(t_data *data, int output_fd)
{
	ft_putstr_fd(data->pwd, output_fd);
	ft_putchar_fd('\n', output_fd);
	return (0);
}
