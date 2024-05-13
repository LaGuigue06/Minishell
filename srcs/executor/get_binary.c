/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:31:51 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/13 16:44:22 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_binary(char **path, char *cmd)
{
	char	*current_binary;
	char	*temp;
	size_t	index;

	index = 0;
	while (path[index])
	{
		temp = ft_strjoin(path[index], "/");
		current_binary = ft_strjoin(temp, cmd);
		free(temp);
		temp = NULL;
		if (access(current_binary, F_OK | X_OK) == 0)
			return (current_binary);
		free(current_binary);
		current_binary = NULL;
		++index;
	}
	return (NULL);
}
