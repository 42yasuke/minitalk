# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose <jose@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 22:22:45 by jose              #+#    #+#              #
#    Updated: 2023/01/15 22:49:07 by jose             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

CFLAGS_OBJ = -Wall -Werror -Wextra -g -c

RM = rm -f

LIB = libft/

NAME = minitalk

all : $(NAME)

%.o : %.c
			$(CC) $(CFLAGS_OBJ) $< -o $@

client : client.o
			$(CC) $(CFLAGS) $< -o $@ -L. -lft

server : server.o
			$(CC) $(CFLAGS) $< -o $@ -L. -lft

libft.a :
			make bonus -C $(LIB)

$(NAME) : libft.a server client

clean :
			make clean -C $(LIB)
			$(RM) *.o

fclean : clean
			$(RM) libft.a server client

re : fclean all

.PHONY : all fclean re clean