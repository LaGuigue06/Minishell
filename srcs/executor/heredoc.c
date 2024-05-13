/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:56:12 by laguigue          #+#    #+#             */
/*   Updated: 2024/05/13 14:59:39 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_heredoc(t_data *data, t_parser *parser)
{
	int		fd;
	char	*line;

	if (parser->delimiter == NULL)
		return ;
	fd = open(".heredoc_temp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	line = readline("> ");
	(void) data;
	while (line && ft_strcmp(line, parser->delimiter) != 0)
	{
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
		line = readline("> ");
	}
	close(fd);
	free(line);
}
