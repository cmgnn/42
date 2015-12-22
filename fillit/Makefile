CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fillit
SRC = main.c algorithms.c init.c
INC = head.h
LIB = -lft
all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB)

clean:
	rm -f $(NAME)

re:	clean
	all

