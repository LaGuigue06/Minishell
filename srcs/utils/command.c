/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:02:40 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/04 13:16:47 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

// init command with data

t_command   *init_command(char *cmd, t_command **previous)
{
    t_command   *command;
    char    **args;

    command = malloc(sizeof(t_command));
    add_command(previous, command);
    args = ft_split(cmd, " ");
    command->name = args[0];
    command->next = NULL;
    command->input_fd = 0;
    command->output_fd = 0;
    init_args(command, args);
    return (command);
}

void    init_args(t_command *command, char **args)
{
    t_arg   *arg;
    t_arg   *c_args;
    int     i;

    i = 1;
    c_args = malloc(sizeof(t_arg));
    c_args->arg = NULL;
    c_args->next = NULL;
    c_args->previous = NULL;
    while (args[i])
    {
        arg = malloc(sizeof(t_arg));
        arg->next = NULL;
        arg->previous = NULL;
        arg->arg = args[i];
        add_arg(&c_args, arg);
        i++;
    }
    command->arg = c_args;
}

void    print_command(t_command *command) // used for debug
{
    t_arg *arg;
    
    printf("==== Command ====\n");
    printf("Command name/file: %s\n input_fd %d\n output_fd %d\n", command->name, command->input_fd, command->output_fd);
    arg = command->arg;
    printf("==== Args ====\n");
    while (arg && arg->arg)
    {
        printf("arg: %s\n", arg->arg);
        arg = arg->next;
    }
}

t_command   *get_last_command(t_command *commands)
{
    t_command *cmd;
    
    cmd = commands;
    if (!cmd->next)
        return (cmd);
    while (cmd->next)
    {
        cmd = cmd->next;
    }
    return (cmd);
}

void    add_command(t_command **lst, t_command *command)
{
    t_command *last;
    if (lst)
    {
        if (*lst)
        {
            last = get_last_command(*lst);
            last->next = command;
            command->previous = last;
        }
        else
            *lst = command;
    }
}