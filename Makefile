NAME = minishell
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
INCLUDES = -I./includes

SRCS =	srcs/minishell.c\
		srcs/parsing.c\
		srcs/execute.c\
		srcs/utils/ft_bzero.c\
		srcs/utils/ft_calloc.c\
		srcs/utils/ft_split.c\
		srcs/utils/ft_free.c\
		srcs/utils/lst_new.c\
		srcs/utils/lst_add_back.c\
		srcs/utils/lst_add_front.c\
		srcs/utils/find_path.c\
		srcs/utils/get_path.c\
		srcs/utils/ft_strcmp.c\
		srcs/utils/ft_strlen.c\
		srcs/utils/ft_strdup.c\
		srcs/utils/ft_strjoin.c\
		srcs/utils/lst_size.c\
		srcs/utils/get_binary.c\
		srcs/get_next_line/get_next_line_utils.c\
		srcs/get_next_line/get_next_line.c\

OBJS = $(SRCS:.c=.o)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re