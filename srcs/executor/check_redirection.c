/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumeroustan <guillaumeroustan@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:59:17 by guillaumero       #+#    #+#             */
/*   Updated: 2024/05/13 14:28:19 by guillaumero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	do_infile(t_lexer *lexer)
{
	int	fd;

	fd = open(lexer->word, O_RDONLY, 0777);
	if (fd < 0)
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		write(STDERR_FILENO, lexer->word, ft_strlen(lexer->word));
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		exit(127);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("Minishell: Dup error\n", STDERR_FILENO);
		exit(127);
	}
	close(fd);
}

static void	do_outfile(t_lexer *lexer)
{
	int	fd;

	fd = open(lexer->word, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd < 0)
	{
		ft_putstr_fd("Minishell: outfile error\n", STDERR_FILENO);
		exit(127);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("Minishell: Dup error\n", STDERR_FILENO);
		exit(127);
	}
	close(fd);
}

static void	do_outfile_append(t_lexer *lexer)
{
	int	fd;

	fd = open(lexer->word, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd < 0)
	{
		ft_putstr_fd("Minishelle: outfile error\n", STDERR_FILENO);
		exit(127);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("Minishell: Dup error\n", STDERR_FILENO);
		exit(127);
	}
	close(fd);
}

static void	do_heredoc(void)
{
	int	fd;

	fd = open(".heredoc_temp", O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Minishell: heredoc error\n", STDERR_FILENO);
		exit(127);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("Minishell: Dup error\n", STDERR_FILENO);
		exit(127);
	}
	close(fd);
	unlink(".heredoc_temp");
}

void	check_redirection(t_parser *parser)
{
	t_lexer	*redirection;

	redirection = parser->redir;
	while (redirection)
	{
		if (redirection->token == ONE_LEFT)
			do_infile(redirection->next);
		if (redirection->token == ONE_RIGHT)
			do_outfile(redirection->next);
		if (redirection->token == TWO_RIGHT)
			do_outfile_append(redirection->next);
		if (redirection->token == TWO_LEFT)
			do_heredoc();
		redirection = redirection->next;
	}
}
