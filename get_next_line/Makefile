CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = test_gnl
OBJ = get_next_line.o main.o
SRC = get_next_line.c main.c
LIB = -lft
all: $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -I libft/includes -o $@ -c $< -lft
	
$(NAME): $(OBJ)
	$(CC) -Wall -Wextra -o $(NAME) $(OBJ) -I libft/includes -L libft/ $(LIB)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
