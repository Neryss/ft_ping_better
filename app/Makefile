CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -g3
INCLUDE_PATH=-I./includes

NAME=ft_ping

INCLUDES= \
			includes/ft_ping.h \
			includes/parser.h \
			includes/parser_utils.h \
			includes/flags.h \
			includes/errors.h \
			includes/packets.h \
			includes/packets_utils.h \
			includes/network.h \
			includes/signals.h \

SRCS= \
			srcs/main.c \
			srcs/parser.c \
			srcs/parser_utils.c \
			srcs/flags.c \
			srcs/errors.c \
			srcs/packets.c \
			srcs/packets_utils.c \
			srcs/network.c \
			srcs/ft_ping.c \
			srcs/signals.c \

OBJS= $(SRCS:%.c=%.o)

%.o: %.c Makefile $(INCLUDES)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE_PATH) -o $(NAME)

all: $(NAME)

fclean:
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean
	$(MAKE)

run: all
	./$(NAME)

.PHONY: all clean fclean re
