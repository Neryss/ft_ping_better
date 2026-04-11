CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic
INCLUDE_PATH=-I./includes

NAME=ft_ping

INCLUDES= \
			includes/ft_ping.h \
			includes/parser.h \
			includes/parser_utils.h \
			includes/flags.h \
			includes/errors.h \

SRCS= \
			srcs/main.c \
			srcs/parser.c \
			srcs/parser_utils.c \
			srcs/flags.c \
			srcs/errors.c \

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
