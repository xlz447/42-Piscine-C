/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 01:33:20 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/25 01:54:50 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define OPEN 1
# define CLOSE 0

typedef int		t_ft_bool;

typedef struct	s_door
{
	int	state;
}				t_door;

void			ft_putstr(char *str);
void			open_door(t_door *door);
void			close_door(t_door *door);
t_ft_bool		is_door_open(t_door *door);
t_ft_bool		is_door_close(t_door *door);
#endif
