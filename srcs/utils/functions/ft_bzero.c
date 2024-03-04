/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:03:05 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 12:11:30 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_bzero(void *data, size_t	size)
{
	unsigned char	*temp;
	size_t			i;

	temp = data;
	i = 0;
	while (i < size)
		temp[i++] = 0;
}
