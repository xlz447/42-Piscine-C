/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:24:00 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/02 16:24:02 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>

typedef struct		s_stack
{
	struct s_stack	*next;
	char			data;
}					t_stack;

int					is_empty(t_stack *current);
t_stack				*new_node(char c);
char				peek(t_stack *current);
void				push(t_stack **current, char c);
char				*pop(t_stack **current);

#endif
