# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keiito <keiito@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 23:57:45 by stanaka2          #+#    #+#              #
#    Updated: 2025/02/23 11:09:33 by keiito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRCS = main.c
SRCS += ${addsuffix .c, check_key ft_isdigit ft_isprintable ft_isspace ft_putstr ft_split ft_strcat ft_strncat ft_strcpy ft_strdup ft_strlen ft_strncpy ft_strndup hash_table node read_dict search_dict strjoin_dict strnum_cmp}
OBJS = ${SRCS:.c=.o}

CC		= cc
# CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror

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
