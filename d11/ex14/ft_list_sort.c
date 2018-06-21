/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:10:23 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/29 21:10:26 by xzhu             ###   ########.fr       */
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
