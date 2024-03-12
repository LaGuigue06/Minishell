/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:51:03 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/12 12:50:07 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_env(char **env, int output_fd)
{
    int i;

    i = 0;
    while (env[i])
    {
        ft_putstr_fd(env[i], output_fd);
        ft_putchar_fd('=', output_fd);
        ft_putstr_fd(env[i], output_fd);
        ft_putchar_fd('\n', output_fd);
        i++;
    }
    return (0);
}