# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/19 13:03:29 by seukim            #+#    #+#              #
#    Updated: 2026/08/09 20:47:15 by seukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): server.o
	$(CC) $(CFLAGS) server.o -o $(SERVER)

$(CLIENT): client.o
	$(CC) $(CFLAGS) client.o -o $(CLIENT)

$(SERVER_BONUS): server_bonus.o
	$(CC) $(CFLAGS) server_bonus.o -o $(SERVER_BONUS)

$(CLIENT_BONUS): client_bonus.o
	$(CC) $(CFLAGS) client_bonus.o -o $(CLIENT_BONUS)

server.o: server.c minitalk.h
	$(CC) $(CFLAGS) -c server.c -o server.o

client.o: client.c minitalk.h
	$(CC) $(CFLAGS) -c client.c -o client.o

server_bonus.o: server_bonus.c minitalk.h
	$(CC) $(CFLAGS) -c server_bonus.c -o server_bonus.o

client_bonus.o: client_bonus.c minitalk.h
	$(CC) $(CFLAGS) -c client_bonus.c -o client_bonus.o

clean:
	rm -f server.o client.o server_bonus.o client_bonus.o

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re