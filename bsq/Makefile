# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keiito <keiito@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 16:47:05 by tmizumur          #+#    #+#              #
#    Updated: 2025/02/26 20:44:08 by keiito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = main.c
SRCS += ${addsuffix .c, get_map algorithm check_map read_file ft_strlen ft_strcpy ft_strcat utility utility2 get_keys}
OBJS = ${SRCS:.c=.o}

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re