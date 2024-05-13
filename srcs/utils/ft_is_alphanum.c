/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_alphanum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:59:34 by gurousta          #+#    #+#             */
/*   Updated: 2024/04/04 16:50:33 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_alphanum(char c)
{
	int	index;

	index = 0;
	while (index < 10)
	{
		if (c == '0' + index)
			return (1);
		++index;
	}
	return (0);
}
