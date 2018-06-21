# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 12:01:54 by xzhu              #+#    #+#              #
#    Updated: 2018/05/28 14:03:30 by xzhu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op

SRC = do_op.c ft_add.c ft_atoi.c ft_div.c ft_mul.c ft_sub.c ft_mod.c ft_usage.c

.PHONY: all clean re

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
		/bin/rm -f $(NAME)

re: 	clean all
