# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 23:57:45 by stanaka2          #+#    #+#              #
#    Updated: 2025/02/23 17:05:47 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRCS = main.c
SRCS += ${addsuffix .c, bonus_insert check_key ft_isdigit ft_isprintable ft_isspace ft_split ft_strcat ft_strncat ft_strcpy ft_strdup ft_strlen ft_strncpy ft_strndup is_malloc_success node read_key open_dict parse_dict print_output read_dict search_dict search_key strjoin_dict strnum_cmp}
OBJS = ${SRCS:.c=.o}

CC		= cc
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
