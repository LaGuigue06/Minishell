/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:59:22 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/04 14:17:22 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUITE_H
# define SUITE_H

# include "command.h"

/*
    Une suite correspond à toutes les commandes entre ';'
    commands: Liste chaînée des commandes de la suite
    next_suite: suite suivante
    initial_str: châine passée avant parsing (séparée par ';')
*/
typedef struct s_suite
{
    t_command       *commands;
    struct s_suite  *next_suite;
    char            *initial_str;
}   t_suite;

#endif