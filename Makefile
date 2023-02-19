# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 14:45:14 by mbelouar          #+#    #+#              #
#    Updated: 2023/02/16 22:45:40 by mbelouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

SRC_CLIENT = src/client.c  src/minitalk_utils.c 

SRC_SERVER = src/server.c 

OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

OBJ_SERVER =  ${SRC_SERVER:.c=.o}

SRC_CLIENT_BONUS = src/client_bonus.c  src/minitalk_utils.c 

SRC_SERVER_BONUS = src/server_bonus.c

OBJ_CLIENT_BONUS = ${SRC_CLIENT_BONUS:.c=.o}

OBJ_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}

NAME: server client 

all : NAME

server: $(OBJ_SERVER)
		$(CC) $(CFLAGS) $(OBJ_SERVER) ft_printf/libftprintf.a -o server

client: $(OBJ_CLIENT)
		$(CC) $(CFLAGS) $(OBJ_CLIENT) ft_printf/libftprintf.a -o client

bonus: server_bonus client_bonus

server_bonus: $(OBJ_SERVER_BONUS)
		$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) ft_printf/libftprintf.a -o server_bonus

client_bonus: $(OBJ_CLIENT_BONUS)
		$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) ft_printf/libftprintf.a -o client_bonus

clean:
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
fclean : clean
	@rm -f server server_bonus client client_bonus

re : fclean all