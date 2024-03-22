/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup_exclude.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:57:36 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/22 17:59:24 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_varname_len(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			break ;
		i++;
	}
	return (i);
}

char	**ft_arrdup_exclude(char **arr, char *excluded)
{
	char	**result;
	char	*var_name;
	size_t	index;
	size_t	size;

	index = 0;
	while (arr[index])
		++index;
	result = ft_calloc(sizeof(char *), index + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	size = 0;
	while (arr[index])
	{
		var_name = ft_substr(arr[index], 0, ft_varname_len(arr[index]));
		if (ft_strcmp(excluded, var_name) != 0)
			result[size++] = ft_strdup(arr[index++]);
		free(var_name);
	}
	result[index] = NULL;
	return (result);
}
