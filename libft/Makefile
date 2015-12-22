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
SRCS = ./
OBJ = ft_memset.o $(SRCS)ft_bzero.o $(SRCS)ft_memcpy.o $(SRCS)ft_memmove.o $(SRCS)ft_memchr.o ft_memdel.o\
	$(SRCS)ft_memcmp.o $(SRCS)ft_strlen.o $(SRCS)ft_strdup.o $(SRCS)ft_strcpy.o $(SRCS)ft_strncpy.o $(SRCS)ft_strcat.o \
	$(SRCS)ft_strncat.o $(SRCS)ft_strlcat.o $(SRCS)ft_strchr.o $(SRCS)ft_strrchr.o $(SRCS)ft_strstr.o \
	$(SRCS)ft_strnstr.o $(SRCS)ft_strcmp.o $(SRCS)ft_strncmp.o $(SRCS)ft_atoi.o $(SRCS)ft_isalpha.o $(SRCS)ft_isdigit.o \
	$(SRCS)ft_isalnum.o $(SRCS)ft_isascii.o $(SRCS)ft_isprint.o $(SRCS)ft_toupper.o $(SRCS)ft_tolower.o \
	$(SRCS)ft_memalloc.o $(SRCS)ft_memdel.o $(SRCS)ft_strnew.o $(SRCS)ft_strdel.o $(SRCS)ft_strclr.o \
	$(SRCS)ft_striter.o $(SRCS)ft_striteri.o $(SRCS)ft_strmap.o $(SRCS)ft_strmapi.o $(SRCS)ft_strequ.o \
	$(SRCS)ft_strnequ.o $(SRCS)ft_strsub.o $(SRCS)ft_strjoin.o $(SRCS)ft_strtrim.o $(SRCS)ft_strsplit.o \
	$(SRCS)ft_itoa.o $(SRCS)ft_putchar.o $(SRCS)ft_putstr.o $(SRCS)ft_putendl.o $(SRCS)ft_putnbr.o \
	$(SRCS)ft_putchar_fd.o $(SRCS)ft_putstr_fd.o $(SRCS)ft_putendl_fd.o $(SRCS)ft_putnbr_fd.o \
	$(SRCS)ft_lstnew.o $(SRCS)ft_lstdelone.o $(SRCS)ft_lstdel.o $(SRCS)ft_lstadd.o $(SRCS)ft_lstiter.o \
	$(SRCS)ft_lstmap.o $(SRCS)ft_memccpy.o \
	$(SRCS)ft_putnbr_base_fd.o $(SRCS)ft_putnbr_base.o ft_btreenew.o ft_btreeadd.o ft_btreefree.o\

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(SRCS)*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

addlib:
			@echo "May sure to have root permissions"
			sudo cp -f $(NAME) /usr/lib/
