/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:05:20 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 12:11:39 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	*ft_calloc(size_t elem_size, size_t elem_num)
{
	void	*result;

	if (elem_num * elem_size == 0)
		return (malloc(0));
	result = malloc(elem_size * elem_num);
	if (!result)
		return (NULL);
	ft_bzero(result, elem_size * elem_num);
	return (result);
}
