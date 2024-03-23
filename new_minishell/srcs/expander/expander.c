/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:45:51 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/23 20:04:19 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*									Expander				
il n'est pas finit...
to do:
	-$? qui doit renvoyer l'error num de la derniere serie de comande
	-[] {} 0123456789 % ' " $ sont les caratere qui arrete l'expander !
*/

int	expander_stop(char c)
{
	return (c == '[' || c == ']'
		|| c == '{' || c == '}'
		|| c == '%' || c == 34
		|| c == 39 || c == '$'
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
