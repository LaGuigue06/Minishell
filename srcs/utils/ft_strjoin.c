/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:36:48 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/12 15:12:09 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	index;
	size_t	index_result;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	index_result = 0;
	while (s1[index])
		result[index_result++] = s1[index++];
	index = 0;
	while (s2[index])
		result[index_result++] = s2[index++];
	result[index_result] = '\0';
	return (result);
}
