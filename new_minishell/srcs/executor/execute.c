/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:20:16 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/12 14:39:55 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute(t_parser *parser, t_data *data)
{
    if (parser->builtin)
        return (execute_builtin(parser, data));
    else
        ft_putstr_fd("todo: Exec cmd\n", 0);
    return (0);
}