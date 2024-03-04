NAME = minishell
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -lreadline
INCLUDES = -I./includes

UTILS_SRCS= $(addprefix srcs/utils/, \
suite.c \
command.c \
arg.c)

UTILS_FUNCS= $(addprefix srcs/utils/functions/, \
ft_bzero.c \
ft_calloc.c \
ft_split.c \
ft_free.c \
lst_new.c \
lst_add_back.c \
lst_add_front.c \
find_path.c \
get_path.c \
ft_strcmp.c \
ft_strlen.c \
ft_strdup.c \
ft_strjoin.c \
lst_size.c \
get_binary.c)

GNL_UTILS= $(addprefix srcs/get_next_line/, \
get_next_line_utils.c \
get_next_line.c)

EXECUTION_SRCS= $(addprefix srcs/execution/, \
execute.c)

PARSING_SRCS= $(addprefix srcs/parsing/, \
parsing.c)

SRCS= $(EXECUTION_SRCS) $(PARSING_SRCS) $(UTILS_SRCS) $(UTILS_FUNCS) $(GNL_UTILS) \
$(addprefix srcs/, \
minishell.c)

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