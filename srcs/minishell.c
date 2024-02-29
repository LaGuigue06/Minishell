/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:59:04 by laguigue          #+#    #+#             */
/*   Updated: 2024/02/29 20:38:33 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_list	*cmd;
	char	*line;
	(void)argc;
	(void)argv;

	while (1)
	{
		write(1, "Minishell>>", 12);
		line = get_next_line(0);
		cmd = parse(line);
		ft_execute(cmd, env);
	}
	return (0);
}