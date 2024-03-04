/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:32:04 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 12:11:51 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	index;
	size_t	index_result;
	char	*result;

	result = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	index = 0;
	index_result = 0;
	while (s1[index])
	{
		result[index_result] = s1[index];
		++index;
		++index_result;
	}
	index = 0;
	while (s2[index])
	{
		result[index_result] = s2[index];
		++index_result;
		++index;
	}
	result[index_result] = '\0';
	return (result);
}
