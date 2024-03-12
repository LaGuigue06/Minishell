NAME = minishell
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -lreadline
INCLUDES = -I./includes

UTILS_SRCS= $(addprefix srcs/utils/, \
ft_putchar_fd.c\
ft_bzero.c\
ft_calloc.c\
ft_free.c\
ft_split.c\
ft_substr.c\
ft_strlen.c\
ft_strdup.c\
ft_arrdup.c\
ft_putstr_fd.c\
ft_strcmp.c\
error.c\
ft_strtrim_cmd.c)

LEXER_SRCS= $(addprefix srcs/lexer/, \
lexer.c\
lexer_add.c\
lexer_new.c\
parse_quote.c\
check_token.c\
lexer_split.c)

BUILTINS= $(addprefix srcs/executor/builtins/, \
builtin_echo.c \
builtin_env.c \
builtins_executor.c)

EXECUTION_SRCS= $(BUILTINS) $(addprefix srcs/executor/, \
execute.c)

PARSER_SRCS= $(addprefix srcs/parser/, \
parser_add.c\
parser_new.c\
parser.c\
get_cmd.c\
get_args.c\
get_delimiter.c)

SRCS= $(EXECUTION_SRCS) $(PARSING_SRCS) $(UTILS_SRCS) $(LEXER_SRCS) $(PARSER_SRCS)\
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