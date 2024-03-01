/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:50:09 by laguigue          #+#    #+#             */
/*   Updated: 2024/02/29 20:42:22 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char **get_argument(t_list *cmd)
{
	t_list	*head;
	char	**result;
	size_t	index;

	result = ft_calloc(sizeof(char *), lst_size(cmd) + 1);
	if (!result)
		return (NULL);
	head = cmd;
	index = 0;
	while (head)
	{
		result[index++] = ft_strdup(head->data);
		head = head->next;
	}
	result[index] = NULL;
	return (result);
}

static void	do_one_cmd(t_list *cmd, char **env)
{
	char	**argv;
	char	*binary;
	pid_t	pid;

	pid = fork();
	/*if (pid == -1)
		return_error();*/
	if (pid == 0)
	{
		argv = get_argument(cmd);
		binary = get_binary(argv[0], env);
		if (execve(binary, argv, env) == -1)
		{
			ft_free_tab(argv);
			free(binary);
		}
	}
	wait(NULL);
}


void	ft_execute(t_list *cmd, char **env)
{
	t_list	*head;

	head = cmd;
	while (head && head->type != WORD)
		head = head->next;
	if (head == NULL)
		do_one_cmd(cmd, env);
	/*else if (head->type == PIPE)
		to_do();
	else if (head->type == REDIRECTION_1_left)
		to_do();
	else if (head->type == REDIRECTION_2_left)
		to_do();
	else if (head->type == REDIRECTION_1_right)
		to_do();
	else if (head->type == REDIRECTION_2_right)
		to_do()*/
}