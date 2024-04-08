/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:46:34 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/12 11:17:10 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	get_size(char *cmd)
{
	size_t	index;

	index = 0;
	if (cmd[index])
		++index;
	return (index);
}

char	*ft_strtrim_cmd(char *cmd)
{
	char	*result;
	size_t	index;
	size_t	index_result;

	index = 1;
	index_result = 0;
	if (cmd == NULL)
		return (NULL);
	if (cmd[0] != 34 && cmd[0] != 39)
		return (ft_strdup(cmd));
	result = ft_calloc(sizeof(char), get_size(cmd) - 1);
	if (result == NULL)
		return (NULL);
	while (cmd[index + 1])
	{
		result[index_result] = cmd[index];
		++index_result;
		++index;
	}
	result[index_result] = '\0';
	return (result);
}
