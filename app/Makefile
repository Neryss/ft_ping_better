CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic

NAME=ft_ping

INCLUDES= \

SRCS= \
			srcs/main.c

OBJS= $(SRCS:%.c=%.o)

%.o: %.c Makefile $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

fclean:
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean
	$(MAKE)

run: all
	./$(NAME)

.PHONY: all clean fclean re
