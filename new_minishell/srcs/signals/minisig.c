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

void	handle_signals(int code, siginfo_t *siginfo, void *context)
{
	(void) context;
	(void) siginfo;
	if (g_pid)
		return ;
	if (code == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		printf("  \b\b");
	}
}

void	minisig_init(t_data *data)
{
	struct sigaction	sig;
	sigset_t			sigset;

	(void) data;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sig.sa_flags = 0;
	sig.sa_sigaction = &handle_signals;
	sig.sa_mask = sigset;
	sigaction(SIGINT, &sig, 0);
}
