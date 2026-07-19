# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/19 13:03:29 by seukim            #+#    #+#              #
#    Updated: 2026/07/19 20:17:49 by seukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): server.o
	$(CC) $(CFLAGS) server.o -o $(SERVER)

$(CLIENT): client.o
	$(CC) $(CFLAGS) client.o -o $(CLIENT)

server.o: server.c
	$(CC) $(CFLAGS) -c server.c -o server.o

client.o: client.c
	$(CC) $(CFLAGS) -c client.c -o client.o

clean:
	rm -f server.o client.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
