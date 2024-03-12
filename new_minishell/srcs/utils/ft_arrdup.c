/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:57:36 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/06 17:22:22 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_arrdup(char **arr)
{
	char	**result;
	size_t	index;

	index = 0;
	while (arr[index])
		++index;
	result = ft_calloc(sizeof(char *), index + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (arr[index])
	{
		result[index] = ft_strdup(arr[index]);
		++index;
	}
	result[index] = NULL;
	return (result);
}
