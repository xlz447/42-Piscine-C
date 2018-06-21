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

NAME = eval_expr

SRC = main.c eval.c eval_helper.c ft_helper.c linkedlist.c  stack.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re: 	fclean all
