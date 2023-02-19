# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afatir <afatir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 18:49:52 by afatir            #+#    #+#              #
#    Updated: 2023/01/12 19:46:48 by afatir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = cc
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus


all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c
		$(CC) $(CFLAGS) client.c minitalk_utils.c -o client

$(SERVER) : server.c
		$(CC) $(CFLAGS) server.c minitalk_utils.c -o server



bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : client_bonus.c
		$(CC) $(CFLAGS) client_bonus.c minitalk_utils.c -o client_bonus

$(SERVER_BONUS) : server_bonus.c
		$(CC) $(CFLAGS) server_bonus.c minitalk_utils.c -o server_bonus
clean:
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
fclean:
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all
