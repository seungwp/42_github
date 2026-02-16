# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 18:01:41 by seukim            #+#    #+#              #
#    Updated: 2026/02/16 16:39:18 by seukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = ./libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
		ft_print_text.c \
		ft_print_numbers.c \
		ft_print_hex.c \
		ft_print_pointer.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
		cp $(LIBFT_NAME) $(NAME)
		$(AR) $(NAME) $(OBJS)

$(LIBFT_NAME):
		make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
