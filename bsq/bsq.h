/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 04:32:38 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/06 04:32:41 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H

# define BSQ_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "linkedlist.h"
# include "global.h"

void			print_all_buf(void);
char			read_file(char *filename);
char			get_grid_dimensions(void);
char			check_input(void);
unsigned int	my_atoi(char *str);
void			solve(void);
char			read_stdin_1st(void);
void			read_stdin_2nd(void);
void			read_stdin_line_len(void);

#endif
