# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/08/11 17:14:40 by fjacquem          #+#    #+#              #
#    Updated: 2015/12/16 00:06:28 by fjacquem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memdel.c\
	ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_memalloc.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	ft_lstmap.c ft_memccpy.c

OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memdel.o\
	ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
	ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o \
	ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o \
	ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
	ft_memalloc.o ft_strnew.o ft_strdel.o ft_strclr.o \
	ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o \
	ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
	ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o \
	ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
	ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o \
	ft_lstmap.o ft_memccpy.o

BONUS_STACK = ft_stknew.o ft_stkinit.o ft_stkempty.o ft_stkfull.o ft_stkclear.o ft_stkpop.o ft_stkpush.o
BONUS_BTREE = ft_btreenew.o ft_btreeadd.o ft_btreefree.o ft_btreeforeach.o
BONUS_IMPLEMENTFCT = ft_putnstr.o ft_pow.o ft_putnbr_base_fd.o ft_putnbr_base.o ft_itoa_base.o ft_print_memory.o ft_printf.o ft_strrev.o ft_putdouble.o ft_puthex.o
BONUS_ALL = $(BONUS_IMPLEMENTFCT) $(BONUS_BTREE) $(BONUS_STACK)
SRC_ALL = $(SRC) 

all: $(NAME)

$(OBJ):
	$(CC) $(FLAGS) -c $(SRC)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(BONUS_ALL)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

dymlib:
			@echo "May sure to have root permissions"
			sudo cp -f $(NAME) /usr/lib/

addstack: $(NAME)
		$(CC) $(FLAGS) -c ft_stknew.c ft_stkinit.c ft_stkempty.c ft_stkfull.c ft_stkclear.c ft_stkpop.c ft_stkpush.c
		ar rc $(NAME)  $(BONUS_STACK)
		ranlib $(NAME)

addbtree: $(NAME)
		$(CC) $(FLAGS) -c ft_btreenew.c ft_btreeadd.c ft_btreefree.c ft_btreeforeach.c
		ar rc $(NAME)  $(BONUS_BTREE)
		ranlib $(NAME)

addfct: $(NAME)
		$(CC) $(FLAGS) -c ft_putnstr.c ft_pow.c ft_putnbr_base_fd.c ft_putnbr_base.c ft_itoa_base.c ft_print_memory.c ft_printf.c ft_strrev.c ft_putdouble.c ft_puthex.c
		ar rc $(NAME)  $(BONUS_IMPLEMENTFCT)
		ranlib $(NAME)

addbonus: $(NAME)
		$(CC) $(FLAGS) -c ft_stknew.c ft_stkinit.c ft_stkempty.c ft_stkfull.c ft_stkclear.c ft_stkpop.c ft_stkpush.c\
		ft_btreenew.c ft_btreeadd.c ft_btreefree.c ft_btreeforeach.c\
		ft_putnstr.c ft_pow.c ft_putnbr_base_fd.c ft_putnbr_base.c ft_itoa_base.c ft_print_memory.c ft_printf.c ft_strrev.c ft_putdouble.c ft_puthex.c
		ar rc $(NAME)  $(BONUS_ALL)
		ranlib $(NAME)
