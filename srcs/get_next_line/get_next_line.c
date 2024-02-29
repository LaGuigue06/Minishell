/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:24:46 by guillaumero       #+#    #+#             */
/*   Updated: 2024/02/29 18:33:17 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract(char *str)
{
	char	*file;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	file = (char *)malloc(sizeof(char) * (ft_len(str) - i + 1));
	if (!file)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	++i;
	while (str[i])
		file[j++] = str[i++];
	file[j] = '\0';
	free(str);
	return (file);
}

char	*get_line_l(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *file)
{
	char	buff[BUFFER_SIZE + 1];
	int		reader;

	reader = 1;
	while (reader)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			if (file)
				free(file);
			return (NULL);
		}
		if (reader == 0)
			break ;
		buff[reader] = '\0';
		file = ft_strjoin_gnl(file, buff);
		if (ft_strchr_gnl(buff, '\n'))
			break ;
	}
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file[FD_SETSIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_SETSIZE)
		return (NULL);
	file[fd] = read_file(fd, file[fd]);
	if (!file[fd])
		return (NULL);
	line = get_line_l(file[fd]);
	file[fd] = extract(file[fd]);
	return (line);
}
