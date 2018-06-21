/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 03:15:52 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/06 03:15:54 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H

# define IO_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "linkedlist.h"
# include "global.h"

unsigned int		my_atoi(char *str);

#endif
