/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumeroustan <guillaumeroustan@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:06:47 by laguigue          #+#    #+#             */
/*   Updated: 2024/05/13 14:29:29 by guillaumero      ###   ########.fr       */
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
# define ONE_RIGHT_SYNTAX_ERROR "Minishell: syntax error near unexpected \
token `>'\n"
# define TWO_RIGHT_SYNTAX_ERROR "Minishell: syntax error near unexpected token \
`>>'\n"
# define ONE_LEFT_SYNTAX_ERROR "Minishell: syntax error near unexpected token \
`<'\n"
# define TWO_LEFT_SYNTAX_ERROR "Minishell: syntax error near unexpected token \
`<<'\n"
# define NEWLINE_SYNTAX_ERROR "Minishell: syntax error near unexpected token \
`newline'\n"
# define PIPE_ERROR "Minishell: pipe failed to initialize"

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
	t_lexer			*redir;
	/*int				input_fd;
	int				output_fd;*/
	struct s_parser	*next;
	struct s_parser	*prev;
}		t_parser;

typedef struct s_data
{
	int			pipe_count;
	int			*pid;
	bool		is_new;
	char		*line;
	char		*pwd;
	char		*old_pwd;
	char		**env;
	char		**path;
	t_lexer		*lexer;
	t_parser	*parser;
}		t_data;

extern int	g_pid;

/*				Utils				*/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		free_arr(char **arr);
void		free_data(t_data *data);
void		free_all(t_data *data);
void		ft_bzero(void *result, size_t size);
void		*ft_calloc(size_t num, size_t size);
void		error(char *err_message, bool is_errno, t_data *data);
void		free_lexer(t_lexer **lexer);
void		free_parser(t_parser **parser);
void		replace_env(char *var, char **env);
int			ft_is_space(char c);
int			ft_is_alphanum(char c);
int			error_pre_loop(char *err_message, t_data *data);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			ft_chararr_size(char **arr);
int			ft_varname_len(char *var);
bool		ft_issubstr(const char *str, const char *to_find);
size_t		ft_strlen(const char *str);
char		*ft_itoa(int num);
char		*ft_strtrim(const char *str, const char *set);
char		*ft_strtrim_cmd(char *cmd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *str);
char		**ft_split(const char *str, const char *charset);
char		**ft_arrdup(char **arr, int additional_mem);
char		**ft_arrdup_exclude(char **arr, char *excluded);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);

/*				Lexer Function		*/

void		lexer(t_data *data);
void		check_token(t_data *data);
void		parse_quote(t_data *data);
void		add_token(t_data *data, size_t *index);
void		get_lexer(t_data *data);
void		add_word(t_data *data, size_t *index);
void		add_token(t_data *data, size_t *index);
bool		is_token(char c);
int			lexer_add(t_lexer **lexer, char *word, int token, bool free_word);
t_lexer		*lexer_new(char *word, int token, t_lexer *prev, bool free_word);

/*				Parser Funcion		*/

void		parser(t_data *data);
int			parser_add(t_parser **parser, t_lexer *lexer, t_data *data);
char		*get_cmd(t_lexer *lexer, t_data *data);
char		*get_delimiter(t_lexer *lexer);
char		**get_args(t_data *data, t_lexer *lexer, char *cmd);
t_parser	*parser_new(t_data *data, t_lexer *lexer, t_parser *prev);
t_lexer		*get_redir(t_data *data, t_lexer *lexer);

/*				Expander fucntion	*/

void		copy_all(t_data *data, char *result, char *str, char **variable);
size_t		get_total_size(t_data *data, char *str, char **variables);
int			expander_stop(char c);
int			expander_cmp(char *variable, char *env);
char		*expander(t_data *data, char *str);
char		**get_all_variable(char *str);

/*				Execute functions	*/

void		check_heredoc(t_data *data, t_parser *parser);
void		handle_cmd(t_data *data, t_parser *parser);
void		check_redirection(t_parser *parser);
int			execute(t_data *data);
int			execute_builtin(t_parser *parser, t_data *data);
int			execute_env(char **env, int output_fd);
int			execute_echo(char **args);
int			execute_pwd(t_data *data, int output_fd);
int			execute_cd(t_data *data, char **args);
int			execute_export(t_data *data, char **args, int output_fd);
int			execute_unset(t_data *data, char **args, int output_fd);
int			simple_cmd(t_data *data, t_parser *parser);
char		*get_binary(char **path, char *cmd);

/*				Main function		*/

int			init_value(t_data *data, char **env, char **argv, int argc);
void		reset_data(t_data *data);
void		minishell(t_data *data);

#endif