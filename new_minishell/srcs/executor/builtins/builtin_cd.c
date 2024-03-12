/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:41:34 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/12 15:11:21 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_cd(t_data *data, char **args)
{
    if (!args[1])
    {
        chdir("~");
        data->old_pwd = data->pwd;
        data->pwd = getenv("HOME");
        return (0);
    }
    if (chdir(args[1]) == -1)
    {
        ft_putstr_fd(strerror(errno), 1);
        ft_putchar_fd('\n', 1);
        return (1);
    }
    data->old_pwd = data->pwd;
    data->pwd = getcwd(NULL, 0);
    return (0);
}
