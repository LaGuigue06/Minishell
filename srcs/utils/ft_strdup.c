/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:58:21 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/06 17:02:13 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	size_t	index;

	result = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (str[index])
	{
		result[index] = str[index];
		++index;
	}
	result[index] = '\0';
	return (result);
}
