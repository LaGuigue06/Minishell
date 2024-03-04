/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:15:51 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/04 13:16:49 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "suite.h"
#include "minishell.h"

t_arg   *get_last_arg(t_arg *args)
{
    t_arg *arg;
    
    arg = args;
    if (!arg)
        return (NULL);
    if (!arg->next)
        return (arg);
    while (arg->next)
    {
        arg = arg->next;
    }
    return (arg);
}

void    add_arg(t_arg **lst, t_arg *arg)
{
    t_arg   *last;
    if (lst)
    {
        if ((*lst)->arg)
        {
            last = get_last_arg(*lst);
            last->next = arg;
            arg->previous = last;
        }
        else
            *lst = arg;
    }
}