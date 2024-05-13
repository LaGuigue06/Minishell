/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <gurousta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:25:13 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/22 20:06:08 by gurousta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	index;

	index = 0;
	if (str == NULL)
		return ;
	while (str[index])
		ft_putchar_fd(str[index++], fd);
}
