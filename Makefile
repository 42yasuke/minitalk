# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 22:22:45 by jose              #+#    #+#              #
#    Updated: 2023/01/19 04:28:18 by jralph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFLAGS_OBJ = -Wall -Werror -Wextra -c

RM = rm -f

LIB = libft/

NAME = minitalk

all : $(NAME)

%.o : %.c
			$(CC) $(CFLAGS_OBJ) $< -o $@

client : client.o
			$(CC) $< -o $@ -L. -lft
			
client_bonus : client_bonus.o
			$(CC) $< -o $@ -L. -lft

server : server.o
			$(CC) $< -o $@ -L. -lft

server_bonus : server_bonus.o
			$(CC) $< -o $@ -L. -lft

libft.a :
			make bonus -C $(LIB)

$(NAME) : libft.a server client

bonus : libft.a server_bonus client_bonus

clean :
			make clean -C $(LIB)
			$(RM) *.o

fclean : clean
			$(RM) libft.a server client server_bonus client_bonus

re : fclean all

.PHONY : all fclean re clean bonus