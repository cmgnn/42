CC = gcc
CFLAGS = -Wall -Wextra
NAME = fillit
SRC = start.c fillit.c solv.c aff.c algorithms.c init.c move_item.c
INC = head.h
LIB = 

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) ../libft/ft_memset.c ../libft/ft_memcpy.c -o $(NAME) $(LIB) -I ../libft/

clean:
	rm -f $(NAME)

re: clean all