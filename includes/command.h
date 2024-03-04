/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:01:18 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/04 14:19:07 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_arg
{
    void    *next; // prochain argument
    void    *previous; // argument précédent
    char    *arg; // argument
}   t_arg;

typedef struct s_command
{
    struct s_command    *previous; // commande précédente
    struct s_command    *next; // commande suivante
    char    *name; // nom de commande (builtin) / exécutable
    t_arg   *arg; // liste chaînée, premier argument
    int input_fd; // fd d'entrée pour gérer pipe / redirect
    int output_fd; // fd de sortie pour gérer pipe / redirect
}   t_command;

t_command   *init_command(char *cmd, t_command **previous);
void    init_args(t_command *command, char **args);
void    print_command(t_command *command);
void    add_arg(t_arg **lst, t_arg *arg);
void    add_command(t_command **lst, t_command *command);
t_command   *get_last_command(t_command *commands);
t_arg   *get_last_arg(t_arg *args);

#endif