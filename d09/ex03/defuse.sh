# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    defuse.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 20:20:52 by xzhu              #+#    #+#              #
#    Updated: 2018/05/24 20:58:21 by xzhu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo $(($(stat -f%a bomb.txt) - 1 ));
