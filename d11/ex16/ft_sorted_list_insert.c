/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:36:02 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/30 16:36:03 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*temp;
	t_list	*head;
	void	*data;

	head = *begin_list;
	while (head)
	{
		temp = *begin_list;
		while (temp->next)
		{
			if ((*cmp)(temp->data, temp->next->data) > 0)
			{
				data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = data;
			}
			temp = temp->next;
		}
		head = head->next;
	}
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *temp;
	t_list *head;

	head = *begin_list;
	temp = ft_create_elem(data);
	if (!head)
		*begin_list = temp;
	else
	{
		temp->next = *begin_list;
		*begin_list = temp;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_list_sort(begin_list, cmp);
}
