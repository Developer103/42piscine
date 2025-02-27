all: libft.a
libft.a:
	cd srcs; cc -Wall -Wextra -Werror -I ../includes -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
	ar -rc libft.a srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
clean:
	rm -f srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
fclean: clean
	rm -f libft.a
re: fclean all