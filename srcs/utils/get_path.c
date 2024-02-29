/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:26:42 by laguigue          #+#    #+#             */
/*   Updated: 2024/02/29 20:33:14 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_path(char **env)
{
	size_t	index;

	index = 0;
	while (env[index])
	{
		if (find_path(env[index], "PATH="))
			return (ft_split(env[index] + 5, ":"));
		++index;
	}
	return (NULL);
}