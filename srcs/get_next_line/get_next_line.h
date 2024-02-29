/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:25:09 by guillaumero       #+#    #+#             */
/*   Updated: 2024/02/29 18:31:46 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/select.h>

size_t	ft_len(char *str);

int		ft_strchr_gnl(char *str, char c);

char	*get_next_line(int fd);
char	*ft_strdup_gnl(char *src);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif