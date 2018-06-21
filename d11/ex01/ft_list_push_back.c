/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:36:30 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/29 12:36:31 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *temp;
	t_list *head;

	head = *begin_list;
	temp = ft_create_elem(data);
	if (!head)
		*begin_list = temp;
	else
	{
		while (head->next)
			head = head->next;
		head->next = temp;
	}
}
