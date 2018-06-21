/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:43:23 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/23 17:24:17 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		i;
	int		*out;

	if (min >= max)
		return (NULL);
	out = (int*)malloc(sizeof(*out) * (max - min));
	i = 0;
	while (i < max - min)
	{
		out[i] = min + i;
		i++;
	}
	return (out);
}
