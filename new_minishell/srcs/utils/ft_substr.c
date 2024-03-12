/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:54:18 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/06 16:55:54 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_substr(const char *str, const char *to_find)
{
	size_t	index;

	index = 0;
	while (str[index] && to_find[index] && str[index] == to_find[index])
	{
		++index;
		if (to_find[index] == '\0')
			return (1);
	}
	return (0);
}
