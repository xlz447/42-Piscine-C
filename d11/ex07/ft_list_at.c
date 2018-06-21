/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 19:06:15 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/29 19:06:16 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*temp;
	unsigned int	i;

	i = 0;
	temp = begin_list;
	if (!begin_list)
		return (NULL);
	while (temp && i < nbr)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}
