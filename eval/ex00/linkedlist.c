/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:25:31 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/02 16:25:33 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_list	*ft_create_elem(void *data)
{
	t_list *out;

	out = (t_list*)malloc(sizeof(*out));
	out->data = data;
	out->next = NULL;
	return (out);
}

void	ft_list_push_back(t_list **begin_list, char *data)
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
