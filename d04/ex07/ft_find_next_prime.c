/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 23:58:22 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/19 15:20:23 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb > 1)
	{
		while (i * i <= nb && i < 46341)
		{
			if (nb % i == 0)
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int		ft_find_next_prime(int nb)
{
	if (nb > 1)
	{
		while (nb < 2147483647 && !ft_is_prime(nb))
		{
			nb++;
		}
		return (nb);
	}
	return (2);
}
