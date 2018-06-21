/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:07:12 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/28 16:07:17 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *out;

	i = 0;
	out = (int*)malloc(sizeof(*out) * length);
	while (i < length)
	{
		out[i] = f(tab[i]);
		i++;
	}
	return (out);
}
