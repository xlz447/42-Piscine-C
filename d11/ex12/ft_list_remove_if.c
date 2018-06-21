/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:35:51 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/29 20:35:54 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *previous;

	current = *begin_list;
	previous = NULL;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			if (!previous)
				*begin_list = (*begin_list)->next;
			else if (!current->next)
				previous->next = NULL;
			else
				previous->next = current->next;
		}
		previous = current;
		current = current->next;
	}
}
