/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:10:12 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 12:11:38 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	find_path(const char *str, const char *to_find)
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

