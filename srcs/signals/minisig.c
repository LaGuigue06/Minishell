/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:44:14 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/28 15:44:23 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minisig.h"

void	handle_signals(int code)
{
	(void) code;
	if (g_pid == 0)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		ft_putstr_fd("  \b\b", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("\n", STDOUT_FILENO);
}

void	minisig_init(t_data *data)
{
	(void) data;
	g_pid = 0;
	signal(SIGINT, &handle_signals);
	signal(SIGQUIT, SIG_IGN);
}
