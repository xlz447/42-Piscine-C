/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 03:32:06 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/06 03:32:07 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H

# define GLOBAL_H
# define BUF_SIZE 4096

typedef struct				s_list
{
	struct s_list			*next;
	char					buf[BUF_SIZE + 1];
	unsigned short			index;
	unsigned short			cursor;
	unsigned short			len;
}							t_list;

t_list				*g_head;
char				g_symb[3];
unsigned short		g_line_num;
unsigned short		g_line_len;

#endif
