/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:45:51 by gurousta          #+#    #+#             */
/*   Updated: 2024/04/16 13:44:49 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	expander_stop(char c)
{
	return (c == '[' || c == ']'
		|| c == '{' || c == '}'
		|| c == '%' || c == 34
		|| c == 39 || c == '$'
		|| c == '?'
		|| ft_is_space(c)
		|| ft_is_alphanum(c));
}

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
