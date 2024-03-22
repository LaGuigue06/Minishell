/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:19:24 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/22 18:55:30 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_echo(char **args)
{
	int	i;

	i = 0;
	if (*args == NULL)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (0);
	}
	while (args[i])
	{
		if ((ft_strcmp(args[0], "-n") == 0) && i == 0)
		{
			++i;
			continue ;
		}
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1] != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
		++i;
	}
	if (args[0] && ft_strcmp(args[0], "-n"))
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
