/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:45:51 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/17 15:59:27 by laguigue         ###   ########.fr       */
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
	int i = 0;
	printf("pour str: %s\n", str);
	while (variable[i])
		printf("%s\n", variable[i++]);
	result = ft_calloc(sizeof(char), get_total_size(data, str, variable) + 100000);
	if (result == NULL)
	{
		free_arr(variable);
		return (NULL);
	}
	copy_all(data, result, str, variable);
	printf("result: %s\n", result);
	free_arr(variable);
	return (result);
}
