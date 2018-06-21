/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:07:05 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/29 15:07:06 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
