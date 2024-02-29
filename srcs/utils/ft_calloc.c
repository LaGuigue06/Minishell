/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:05:20 by laguigue          #+#    #+#             */
/*   Updated: 2024/02/29 17:07:19 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
