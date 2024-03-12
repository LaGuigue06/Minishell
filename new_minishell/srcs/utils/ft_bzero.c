/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:30:22 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/06 16:32:13 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_bzero(void *result, size_t size)
{
	size_t			index;
	unsigned char	*temp;

	temp = (unsigned char *)result;
	index = 0;
	while (index < size)
		temp[index++] = 0;
}
