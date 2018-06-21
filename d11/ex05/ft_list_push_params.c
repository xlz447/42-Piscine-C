/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:00:21 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/29 16:00:25 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*out;
	t_list	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (ac < 1)
		return (NULL);
	while (i < ac)
	{
		out = ft_create_elem(av[i]);
		out->next = temp;
		temp = out;
		i++;
	}
	return (out);
}
