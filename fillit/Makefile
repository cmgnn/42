CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fillit
SRC = main.c algorithms.c init.c
INC = head.h
LIB =
all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB) -I ../libft/

clean:
	rm -f $(NAME)

re:	clean
	all

