/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:23:26 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/02 16:23:27 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		is_empty(t_stack *current)
{
	return (!current);
}

t_stack	*new_node(char c)
{
	t_stack *out;

	out = (t_stack*)malloc(sizeof(*out));
	out->next = NULL;
	out->data = c;
	return (out);
}

char	peek(t_stack *current)
{
	if (!is_empty(current))
		return (current->data);
	else
		return ('~');
}

void	push(t_stack **current, char c)
{
	t_stack *new;

	new = new_node(c);
	if (!(*current))
		*current = new;
	else
	{
		new->next = *current;
		*current = new;
	}
}

char	*pop(t_stack **current)
{
	t_stack	*temp;
	char	*c;

	c = (char*)malloc(sizeof(*c) * 2);
	if (!is_empty(*current))
	{
		temp = *current;
		*current = (*current)->next;
		c[0] = temp->data;
		c[1] = '\0';
		free(temp);
		return (c);
	}
	else
		return ("~");
}
