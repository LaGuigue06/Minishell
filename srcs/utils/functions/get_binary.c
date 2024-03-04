/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:30:13 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 12:11:56 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_binary(char *cmd, char **env)
{
	size_t  index;
    char    **path;
    char    *current_path;
    char    *temp;

    path = get_path(env);
    if (!path)
        return (NULL);
    index = 0;
    while (path[index])
    {
        temp = ft_strjoin(path[index], "/");
        current_path = ft_strjoin(temp, cmd);
        free(temp);
        if (access(current_path, X_OK | F_OK) == 0)
        {
            ft_free_tab(path);
            return (current_path);
        }
        free(current_path);
        ++index;
    }
    ft_free_tab(path);
    return (NULL);
}
