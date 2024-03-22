/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:45:51 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/22 15:20:26 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*expander(t_data *data, char *str)
{
	char	**variable;
	char	*result;

	variable = get_all_variable(str);
	if (variable == NULL)
		return (NULL);
	result = ft_calloc(sizeof(char), get_total_size(data, str, variable) + 1);
	if (result == NULL)
	{
		free_arr(variable);
		return (NULL);
	}
	copy_all(data, result, str, variable);
	free_arr(variable);
	return (result);
}
