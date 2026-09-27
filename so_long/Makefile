NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INC		= -Iincludes -Iminilibx-linux -Ilibft

SRCS	= srcs/main.c
OBJS	= $(SRCS:.c=.o)

LIBFT	= libft/libft.a
MLX		= minilibx-linux/libmlx_Linux.a
LIBS	= -Llibft -lft -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

%.o: %.c includes/so_long.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re