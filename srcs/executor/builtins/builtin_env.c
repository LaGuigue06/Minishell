/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:51:03 by vicalvez          #+#    #+#             */
/*   Updated: 2024/04/16 16:41:22 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_env(char **env, int output_fd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd(env[i], output_fd);
		ft_putchar_fd('\n', output_fd);
		i++;
	}
	return (0);
}
