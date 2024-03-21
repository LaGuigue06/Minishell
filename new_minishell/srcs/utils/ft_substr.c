/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:39:03 by vicalvez          #+#    #+#             */
/*   Updated: 2024/03/21 11:39:57 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
		len = 0;
	if (ft_strlen((char *)s) - start < len)
		len = ft_strlen((char *)s) - start;
	sub = ft_calloc(sizeof(char), len + 1);
	if (!sub)
		return (NULL);
	if (len <= 0)
		return (sub);
	while (s[i + start] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}