/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:36:26 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/22 16:46:14 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	expander_cmp(char *variable, char *current_env)
{
	size_t	index;

	index = 0;
	while (variable[index] && current_env[index]
		&& variable[index] == current_env[index] && current_env[index] != '=')
		++index;
	return (variable[index] - current_env[index]);
}
