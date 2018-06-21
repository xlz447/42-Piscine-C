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

NAME = ft_cat

CC = gcc
CFLAGS = -I ./include/ -Wall -Werror -Wextra

SRCS = ft_cat.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
