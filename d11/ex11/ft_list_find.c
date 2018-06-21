/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:31:33 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/29 20:31:34 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *temp;

	temp = begin_list;
	while (temp)
	{
		if ((*cmp)(temp->data, data_ref) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
