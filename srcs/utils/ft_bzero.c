/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:03:05 by laguigue          #+#    #+#             */
/*   Updated: 2024/02/29 17:05:17 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_bzero(void *data, size_t	size)
{
	unsigned char	*temp;
	size_t			i;

	temp = data;
	i = 0;
	while (i < size)
		temp[i++] = 0;
}
