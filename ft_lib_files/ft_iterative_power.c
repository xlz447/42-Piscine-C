/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:58:40 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/18 15:26:52 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int result;
	int count;

	result = 1;
	count = 0;
	if (power < 0)
	{
		return (0);
	}
	while (count < power)
	{
		result *= nb;
		count++;
	}
	return (result);
}
