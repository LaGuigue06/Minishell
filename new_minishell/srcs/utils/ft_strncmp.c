/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:11:03 by gurousta          #+#    #+#             */
/*   Updated: 2024/03/15 14:18:17 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index] && n != 0 && index < n - 1)
		++index;
	return (s1[index] - s2[index]);
}
