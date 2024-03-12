/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:48:39 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/12 15:34:48 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_data(t_data *data)
{
	size_t		index;
	size_t		index_parser;
	t_lexer		*lexer_head;
	t_parser	*parser_head;

	index = 0;
	lexer_head = data->lexer;
	parser_head = data->parser;
	printf("------------------------------------DEBUT DE TEST------------------------------------\n");
	printf("pour ma data:\n");
	printf("ma ligne: %s\n", data->line);
	printf("le nombre de pipe sur ma ligne: %d\n", data->pipe_count);
	printf("mon pwd: %s\n", data->pwd);
	printf("mon old_pwd: %s\n", data->old_pwd);
	printf("------------------------------------voici mon env------------------------------------\n");
	while (data->env[index])
		printf("%s\n", data->env[index++]);
	index = 0;
	printf("------------------------------------voici mon path------------------------------------\n");
	while (data->path[index])
		printf("%s\n", data->path[index++]);
	printf("------------------------------------voici mon lexer------------------------------------\n");
	index = 0;
	while (lexer_head)
	{
		printf("pour l'iteration %ld: ", index++);
		printf("le mot = %s et le token = %d\n", lexer_head->word, lexer_head->token);
		lexer_head = lexer_head->next;
	}
	printf("------------------------------------voici mon parser------------------------------------\n");
	index = 0;
	while (parser_head)
	{
		printf("pour l'iteration %ld:\n", index++);
		index_parser = 0;
		printf("voici la commande: %s\n", parser_head->cmd);
		printf("voici les arguments:\n");
		while (parser_head->args[index_parser])
			printf("%s\n", parser_head->args[index_parser++]);
		printf("voici le builtin: %d\n", parser_head->builtin);
		printf("voici le delimiter du here_doc: %s\n", parser_head->delimiter);
		printf("voici le input_fd: %d\n", parser_head->input_fd);
		printf("voici le output_fd: %d\n", parser_head->output_fd);
		parser_head = parser_head->next;
	}
	printf("------------------------------------END OF TEST------------------------------------\n");
}

void	reset_data(t_data *data)
{
	free_data(data);
	minishell(data);
}

void	minishell(t_data *data)
{
	data->line = readline(GREEN"Mnishell "RED">> " RESET);
	if (data->line == NULL || data->line[0] == '\0')
		reset_data(data);
	add_history(data->line);
	lexer(data);
	parser(data);
	print_data(data);
	//expandor;
	execute(data);
	reset_data(data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (!init_value(&data, env, argv, argc))
		return (EXIT_FAILURE);
	using_history();
	minishell(&data);
	rl_clear_history();
	return (EXIT_SUCCESS);
}