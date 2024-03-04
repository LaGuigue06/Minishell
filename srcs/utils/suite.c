/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:57:41 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/04 14:39:38 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "suite.h"
#include "minishell.h"

t_suite *parse_suite(t_suite **initial_suite, char *str)
{
    t_suite *suite;
    
    suite = malloc(sizeof(t_suite));
    if (!suite)
        return NULL;
    suite->next_suite = NULL;
    suite->initial_str = str;
    (void) initial_suite;
    (void) suite;
    // todo split commands
    /*
        Ici il faut trouver un moyen de split les commandes mais de garder les pipes et redirections pour les passer
        dans la struct t_command de chaque commande
        
        prog < file
        prog << del
        prog > file
        prog >> file
        prog | prog2

    */
   return (suite);
}