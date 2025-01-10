CC=gcc
NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_count.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_onepercent.c ft_printf.c ft_ptr.c ft_putchar.c ft_putchar_fd.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunbr.c ft_split.c ft_strdup.c ft_strlen.c ft_strvlen.c get_contents.c has_prefix.c has_suffix.c ft_strvfree.c ft_perror.c
HEADER = libft.h
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

run: all
	./$(NAME)

run2: all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME)

re: fclean all

.PHONY: all fclean clean run run2 re
