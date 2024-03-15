/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:45:51 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/15 20:06:49 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//	Etape une avoir toutes les variable
//	Calculer la taille necessaire pour mettre ma string ainsi que toute les variable
//	copier ma string ainsi que les variable dans le bonne ordre

char	*expander(t_data *data, char *str)
{
	char	**variable;
	char	*result;

	variable = get_all_variable(str);
	if (variable == NULL)
		return (NULL);
	result = ft_calloc(sizeof(char), get_total_size(data, str, variable) + 1);
	printf("mon total size = %ld\n", get_total_size(data, str, variable));
	if (result == NULL)
	{
		free_arr(variable);
		return (NULL);
	}
	copy_all(data, result, str, variable);
	free_arr(variable);
	return (result);
}
