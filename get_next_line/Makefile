CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = test_gnl
OBJ = get_next_line.o main.o
SRC = get_next_line.c main.c
LIB = -lft
all: $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -I libft/includes -o $@ -c $<
	
$(NAME): $(OBJ)
	 $(CC) -o $(NAME) $(OBJ) -I libft/includes -L libft/ $(LIB)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

purge: fclean

re:	purge all
