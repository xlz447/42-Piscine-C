/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 03:35:56 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/06 03:35:58 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_list	*ft_create_elem(unsigned short index)
{
	t_list *out;

	out = (t_list*)malloc(sizeof(t_list) * 1);
	out->next = NULL;
	out->index = index;
	out->cursor = 0;
	out->len = 0;
	return (out);
}

void	ft_list_push_back(t_list **begin_list, unsigned short index)
{
	t_list	*new_entry;
	t_list	*i;

	new_entry = ft_create_elem(index);
	if (!*begin_list)
		*begin_list = new_entry;
	else
	{
		i = *begin_list;
		while (i->next)
			i = i->next;
		i->next = new_entry;
	}
}

void	ft_list_clear(t_list **begin_list)
{
	t_list	*place;

	if (!begin_list)
		return ;
	while (*begin_list)
	{
		place = *begin_list;
		*begin_list = (*begin_list)->next;
		free(place);
	}
	*begin_list = NULL;
}
