# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mforest- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 21:55:40 by mforest-          #+#    #+#              #
#    Updated: 2024/12/08 23:03:18 by mforest-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
NAME = so_long
SRCS = srcs/display.c srcs/display_movement.c srcs/parsing_map.c srcs/parsing_map_checker.c srcs/exit_data.c srcs/handle_input.c srcs/handle_input_aux.c srcs/init_data.c srcs/init_assets.c srcs/so_long.c srcs/init_map.c srcs/so_long_utils.c srcs/check_path.c
HEADER = includes/so_long.h
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Iincludes
LDFLAGS = $(MLX) $(LIBFT)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME) $(ARGS)

run2: all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME) $(ARGS)

.PHONY: all fclean clean re run run2
