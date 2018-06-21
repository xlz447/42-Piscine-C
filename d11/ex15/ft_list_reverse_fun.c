/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:42:15 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/30 14:42:22 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_ll(t_list *a, t_list *b)
{
	void *data;

	data = a->data;
	a->data = b->data;
	b->data = data;
}

int		ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*head;

	size = 0;
	head = begin_list;
	if (!head)
		return (0);
	else
	{
		while (head)
		{
			size++;
			head = head->next;
		}
		return (size);
	}
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		length;
	int		i;
	int		j;
	t_list	*temp;
	t_list	*swap;

	if (!begin_list)
		return ;
	temp = begin_list;
	length = ft_list_size(begin_list);
	i = 0;
	while (i <= ((length - 1) / 2))
	{
		j = 0;
		swap = begin_list;
		while (j < length - i - 1)
		{
			swap = swap->next;
			j++;
		}
		swap_ll(temp, swap);
		i++;
		temp = temp->next;
	}
}
