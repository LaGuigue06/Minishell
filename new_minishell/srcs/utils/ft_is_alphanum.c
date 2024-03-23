/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_alphanum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:59:34 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/23 20:05:18 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_alphanum(char c)
{
	size_t	index;
	
	index = 0;
	while (index < 10)
	{
		if (c == '0' + index)
			return (1);
		++index;
	}
	return (0);
}
