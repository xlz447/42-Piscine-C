/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:51:14 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/24 19:38:54 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	if (hour == 0)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %i.00 A.M. AND %i.00 A.M.\n",
				hour + 12, hour + 1);
	else if (hour == 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %i.00 A.M. AND %i.00 P.M.\n",
				hour, hour + 1);
	else if (hour == 12)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %i.00 P.M. AND %i.00 P.M.\n",
				hour, hour - 11);
	else if (hour == 23)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %i.00 P.M. AND %i.00 A.M.\n",
				hour - 12, hour - 11);
	else if (hour == 24)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %i.00 A.M. AND %i.00 A.M.\n",
				hour - 12, hour - 23);
	else if (hour < 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %i.00 A.M. AND %i.00 A.M.\n",
				hour, hour + 1);
	else
		printf("THE FOLLOWING TAKES PLACE BETWEEN %i.00 P.M. AND %i.00 P.M.\n",
				hour - 12, hour - 11);
}
