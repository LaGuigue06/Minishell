/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:57:36 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/21 11:20:13 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_arrdup(char **arr, int additional_mem)
{
	char	**result;
	size_t	index;

	index = 0;
	while (arr[index])
		++index;
	result = ft_calloc(sizeof(char *), index + 1 + additional_mem);
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
