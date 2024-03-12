/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:31:51 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/12 16:01:55 by vicalvez         ###   ########.fr       */
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
		if (access(current_binary, X_OK | F_OK) != -1)
			return (current_binary);
		free(current_binary);
		current_binary = NULL;
		++index;
	}
	return (NULL);
}
