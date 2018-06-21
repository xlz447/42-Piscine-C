/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_helper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:46:19 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/31 17:46:20 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_HELPER_H

# define FT_TAIL_HELPER_H
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

void	normal(char *filename, int offset, int fd);
int g_atoi_mode;

#endif
