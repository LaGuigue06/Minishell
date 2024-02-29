/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:08:19 by laguigue          #+#    #+#             */
/*   Updated: 2024/02/29 19:15:37 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup(char *str)
{
	char	*result;
	size_t	index;

	result = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!result)
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
