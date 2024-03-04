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
        
        prog < file: input def, output = 0
        prog << del: input def seulement si rencontre le char del sinon rien ne s'execute, output = 0
        prog > file: input = 0 ou pipe, output = file en overwrite
        prog >> file: input = 0 ou pipe, output = file en append
        prog | prog2: input = prog, output = 0

        < ou << ont la priorité sur |
        ex: echo "hey" | wc -l < file, le fd de file sera envoyé dans wc -l et non celui du echo

    */
   return (suite);
}
