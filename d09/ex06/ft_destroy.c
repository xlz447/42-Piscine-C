/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:19:31 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/24 23:37:13 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (factory)
	{
		while (factory[i])
		{
			while (factory[i][j])
			{
				free(factory[i][j]);
				j++;
			}
			j = 0;
			free(factory[i]);
			i++;
		}
		free(factory);
	}
}
