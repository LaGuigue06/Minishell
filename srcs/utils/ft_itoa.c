/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:21:26 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/23 20:30:15 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	get_size(int num)
{
	size_t	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		++size;
		num = num / 10;
	}
	return (size);
}

char	*ft_itoa(int num)
{
	char	*result;
	size_t	size;
	size_t	index;

	size = get_size(num);
	index = size - 1;
	result = ft_calloc(sizeof(char), size + 1);
	if (result == NULL)
		return (NULL);
	if (num == 0)
		result[index] = '0';
	while (num)
	{
		result[index] = num % 10 + '0';
		--index;
		num = num / 10;
	}
	result[size] = '\0';
	return (result);
}
