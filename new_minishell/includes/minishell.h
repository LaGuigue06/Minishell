/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:06:47 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/12 12:20:29 by vicalvez         ###   ########.fr       */
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
# include <stdbool.h>

/*				ERROR				*/

# define MALLOC_ERROR "Malloc failed to execute!\n"
# define NO_ARGUMENT "This program does not take any arguments!\n"
# define QUOTE_FAIL "Minishell: syntax error unclosed quote!\n"
# define MISSIMG_COMMAND "Minishell: syntax error missing command!\n"
# define BACKSLASH_TOKEN "Minishell: the backslash token is not allowed!\n"
# define SEMICOLON_TOKEN "Minishell: the semicolon token is not allowed!\n"
# define PIPE_PROMP_TOKEN "Minishell: the pipe prompt token is not allowed!\n"
# define PIPE_SYNTAX_ERROR "Minishell: syntax error near unexpected token `|'\n"
# define ONE_RIGHT_SYNTAX_ERROR "Minishell: syntax error near unexpected token `>'\n"
# define TWO_RIGHT_SYNTAX_ERROR "Minishell: syntax error near unexpected token `>>'\n"
# define ONE_LEFT_SYNTAX_ERROR "Minishell: syntax error near unexpected token `<'\n"
# define TWO_LEFT_SYNTAX_ERROR "Minishell: syntax error near unexpected token `<<'\n"
# define NEWLINE_SYNTAX_ERROR "Minishell: syntax error near unexpected token `newline'\n"

/*				COLORS				*/

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define WHITE "\033[0;37m"
# define RESET "\001\e[0m\002"

/*				Tokens				*/

# define WORD 1
# define PIPE 2			// |
# define ONE_RIGHT 3	// >
# define TWO_RIGHT 4	// >>
# define ONE_LEFT 5		// <
# define TWO_LEFT 6		// <<
# define BACKSLASH 7    // '\\'
# define SEMICOLON 8	// ;
# define PIPE_PROMP 9   // ||

/*				Strcuts				*/

typedef struct s_lexer
{
	char			*word;
	int				token;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}		t_lexer;

typedef struct s_parser
{
	char			**args;
	char			*cmd;
	char			*delimiter;
	int				builtin;
	int				input_fd;
	int				output_fd;
	struct s_parser	*next;
	struct s_parser	*prev;
}		t_parser;

typedef struct s_data
{
	int			pipe_count;
	char		*line;
	char		*pwd;
	char		*old_pwd;
	char		**env;
	char		**path;
	t_lexer		*lexer;
	t_parser	*parser;
}		t_data;

/*				Utils				*/

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	free_arr(char **arr);
void	free_data(t_data *data);
void	free_all(t_data *data);
void	ft_bzero(void *result, size_t size);
void	*ft_calloc(size_t num, size_t size);
void	error(char *err_message, bool is_errno, t_data *data);
int		error_pre_loop(char *err_message, t_data *data);
int		ft_strcmp(char *s1, char *s2);
bool	ft_substr(const char *str, const char *to_find);
size_t	ft_strlen(const char *str);
char	*ft_strtrim_cmd(char *cmd);
char	*ft_strdup(const char *str);
char	**ft_split(const char *str, const char *charset);
char	**ft_arrdup(char **arr);

/*				Lexer Function		*/

void		lexer(t_data *data);
void		check_token(t_data *data);
void		parse_quote(t_data *data);
int			lexer_add(t_lexer **lexer, char *word);
char		**lexer_split(char *line);
t_lexer		*lexer_new(char *word, t_lexer *prev);

/*				Parser Funcion		*/

void		parser(t_data *data);
int			parser_add(t_parser **parser, t_lexer *lexer);
char		*get_cmd(t_lexer *lexer);
char		*get_delimiter(t_lexer *lexer);
char		**get_args(t_lexer *lexer, char *cmd);
t_parser	*parser_new(t_lexer *lexer, t_parser *prev);


/*				Execute functions	*/

int		execute(t_parser *parser, t_data *data);
int		execute_builtin(t_parser *parser, t_data *data);
int		execute_env(char **env, int output_fd);
int		execute_echo(char **args);

/*				Main function		*/

int		init_value(t_data *data, char **env, char **argv, int argc);
void	reset_data(t_data *data);
void	minishell(t_data *data);

#endif