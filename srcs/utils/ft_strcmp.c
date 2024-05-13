/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:06:09 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/22 19:08:50 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[index] && s2[index] && s1[index] == s2[index])
		++index;
	return (s1[index] - s2[index]);
}
