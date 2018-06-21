/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:04:20 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/02 16:09:12 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include <stdlib.h>
# include "stack.h"
# include "linkedlist.h"

int		is_op(char c);
char	*remove_space(char *in);
int		ft_strlen(char *str);
char	*do_op(char *first, char *third, char *op);
int		ft_atoi(char *str);

static int	g_op_flag = 1;

#endif
