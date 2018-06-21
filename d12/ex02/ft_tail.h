/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:25:04 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/31 14:25:05 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H

# define FT_TAIL_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>

void	atoi_mode_helper(char c, int space);
int		ft_str_is_numeric(char *str);
int		ft_strlen(char *str);
void	tail(int argc, char *argv[], int offset);
void	tail_helper(int head_flag, char *argv, int print_use);

int g_atoi_mode;

#endif
