/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:19:24 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/12 12:45:38 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_echo(char **args)
{
    int i;

    i = 0;
    if (!args[i])
    {
        ft_putchar_fd('\n', 1);
        return (0);
    }
    i = 1;
    while (args[i])
    {
        if (ft_strcmp(args[1], "-n") == 0 && i == 1)
            i++;
        if (!args[i])
            break ;
        ft_putstr_fd(args[i], 1);
        if (args[i + 1])
            ft_putchar_fd(' ', 1);
        i++;
    }
    if (args[1] && ft_strcmp(args[1], "-n") > 0)
        ft_putchar_fd('\n', 1);
    return (0);
}