/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chararr_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:21:52 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/22 17:58:39 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_chararr_size(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (i);
	while (arr[i])
		i++;
	return (i);
}
