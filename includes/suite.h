/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:59:22 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/04 12:17:34 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUITE_H
# define SUITE_H

# include "command.h"

typedef struct s_suite
{
    t_command       *commands;
    struct s_suite  *next_suite;
}   t_suite;

#endif