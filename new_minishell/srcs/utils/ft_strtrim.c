/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:01:29 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/22 13:06:56 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	index;

	index = 0;
	i = 0;
	j = ft_strlen(str);
	while (str[i] && ft_is_set(str[i], set))
		++i;
	while (j > i && ft_is_set(str[j - 1], set))
		--j;
	result = (char *)ft_calloc(sizeof(char), (j - i + 1));
	if (!result)
		return (NULL);
	while (i < j)
		result[index++] = str[i++];
	result[index] = '\0';
	return (result);
}
