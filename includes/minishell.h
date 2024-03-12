/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:59:20 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/05 18:41:41 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdint.h>
# include "../srcs/get_next_line/get_next_line.h"
# include "suite.h"

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define WHITE "\033[0;37m"
#define RESET "\001\e[0m\002"

/*					Define different Types		*/

# define WORD 1
# define PIPE 2
# define REDIRECTION_1_right 3		// >
# define REDIRECTION_2_right 4		// >>
# define REDIRECTION_1_left 5		// <
# define REDIRECTION_2_left 6		// <<

/*					Structures					*/

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	void			*data;
	int				type;
}			t_list;

/*					Utils						*/

void	ft_bzero(void *data, size_t size);
void	ft_free_tab(char **map);
void	ft_free_list(t_list *lst);
void	*ft_calloc(size_t elem_size, size_t elem_num);
int		ft_strcmp(const char *s1, const char *s2);
int		find_path(const char *str, const char *to_find);
size_t	ft_strlen(const char *str);
char	*get_binary(char *cmd, char **env);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	**get_path(char **env);
char	**ft_split(const char *str, const char *charset);

/*					Link list functions			*/

t_list	*lst_new(char *data, int type, t_list *prev);
int		lst_add_back(t_list **lst, char *data, int type);
int		lst_add_front(t_list **lst, char *data, int type);
size_t	lst_size(t_list *lst);

/*					Main functions				*/

t_data	*init_value(char **env);
t_list	*parse(char *line);
void	ft_execute(t_list *cmd, char **env);

#endif