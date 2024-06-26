NAME = minishell
CC = gcc
CFLAGS = -g -Wall -Wextra -lreadline
INCLUDES = -I./includes

UTILS_SRCS= $(addprefix srcs/utils/, \
ft_putchar_fd.c\
ft_bzero.c\
ft_calloc.c\
ft_free.c\
ft_split.c\
ft_issubstr.c \
ft_substr.c\
ft_strlen.c\
ft_strdup.c\
ft_arrdup.c\
ft_putstr_fd.c\
ft_strcmp.c\
error.c\
ft_strtrim_cmd.c\
ft_strjoin.c\
ft_strncmp.c \
ft_chararr_size.c \
ft_arrdup_exclude.c\
ft_strchr.c\
ft_strtrim.c\
ft_is_alphanum.c\
ft_is_space.c\
ft_itoa.c)

LEXER_SRCS= $(addprefix srcs/lexer/, \
lexer.c\
lexer_add.c\
lexer_new.c\
parse_quote.c\
check_token.c\
get_lexer.c\
add_token.c\
add_word.c)

BUILTINS= $(addprefix srcs/executor/builtins/, \
builtin_echo.c \
builtin_env.c \
builtin_pwd.c \
builtin_cd.c \
builtin_export.c \
builtin_unset.c \
builtins_executor.c)

EXECUTION_SRCS= $(BUILTINS) $(addprefix srcs/executor/, \
execute.c\
get_binary.c\
simple_cmd.c\
handle_cmd.c\
heredoc.c\
check_redirection.c)

PARSER_SRCS= $(addprefix srcs/parser/, \
parser_add.c\
parser_new.c\
parser.c\
get_cmd.c\
get_args.c\
get_delimiter.c\
get_redir.c)

EXPANDER_SRC= $(addprefix srcs/expander/, \
expander.c\
get_all_variable.c\
get_total_size.c\
copy_all.c\
expander_cmp.c)

MINISIG= $(addprefix srcs/signals/, \
minisig.c)

SRCS= $(EXECUTION_SRCS) $(PARSING_SRCS) $(UTILS_SRCS) $(LEXER_SRCS) $(PARSER_SRCS) $(EXPANDER_SRC) $(MINISIG)\
$(addprefix srcs/, \
minishell.c\
init_value.c)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

leaks:
	valgrind ./$(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re leaks