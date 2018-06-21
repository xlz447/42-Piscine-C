/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:05:52 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/30 17:05:54 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *temp;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	temp = *begin_list1;
	while (temp->next)
		temp = temp->next;
	temp->next = begin_list2;
}

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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
