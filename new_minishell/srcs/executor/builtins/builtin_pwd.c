/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:14 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/22 17:54:22 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pwd(t_data *data, int output_fd)
{
	ft_putstr_fd(data->pwd, output_fd);
	ft_putchar_fd('\n', output_fd);
	return (0);
}
