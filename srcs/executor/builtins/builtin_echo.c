/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:19:24 by vicalvez          #+#    #+#             */
/*   Updated: 2024/04/16 11:51:19 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_option(char *arg)
{
	size_t	index;

	index = 1;
	if (arg == NULL || arg[0] == '\0' || arg[1] == '\0')
		return (0);
	while (arg[index] && arg[index] == 'n' && arg[0] == '-')
		++index;
	return (arg[index] == '\0');
}

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
		if (check_option(args[i]) && i == 0)
		{
			while (check_option(args[i]))
				++i;
			if (args[i] == NULL)
				break ;
		}
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1] != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
		++i;
	}
	if (args[0] && check_option(args[0]) == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
