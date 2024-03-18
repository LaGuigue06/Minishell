/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:36:26 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/16 15:47:22 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	expander_cmp(char *variable, char *current_env)
{
	size_t	index;

	index = 0;
	while (variable[index] && current_env[index] && variable[index] == current_env[index] && current_env[index] != '=')
		++index;
	return (variable[index] - current_env[index]);
}