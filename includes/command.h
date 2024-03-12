/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:01:18 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/05 18:39:45 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef enum s_token
{
	WORD = 1,
	PIPE = 2,
	REDIRECTION_1_right = 3,		// >
	REDIRECTION_2_right = 4,	// >>
	REDIRECTION_1_left = 5,		// <
	REDIRECTION_2_left = 6,		// <<
}		t_token;

typedef struct s_arg
{
	void	*next; // prochain argument
	void	*previous; // argument précédent
	char	*arg; // argument
	t_token token; // le type d'argument
}   t_arg;

typedef struct s_command
{
	struct s_command    *previous; // commande précédente
	struct s_command    *next; // commande suivante
	t_arg   *arg; // liste chaînée, avec le binaire/excutable + args et redirection
	int input_fd; // fd d'entrée pour gérer pipe / redirect
	int output_fd; // fd de sortie pour gérer pipe / redirect
}   t_command;

typedef	struct s_data
{
	char		**path;
	char		**env;
	char		*pwd;
    char        *old_pwd;
	t_command	*cmd;
}		t_data;

t_command   *init_command(char *cmd);
void    init_args(t_command *command, char **args);
void    print_command(t_command *command);
void    add_arg(t_arg **lst, t_arg *arg);
void    add_command(t_command **lst, t_command *command);
t_command   *get_last_command(t_command *commands);
t_arg   *get_last_arg(t_arg *args);

#endif