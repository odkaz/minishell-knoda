NAME := minishell
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCS := lsh_echo.c lsh_pwd.c lsh_exit.c lsh_help.c lsh_cd.c
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) main.c $(OBJS) -o $(NAME)
all: $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re .c.o
