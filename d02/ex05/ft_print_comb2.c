/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:02:30 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/17 21:28:09 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb2(void)
{
	int num[2];

	num[0] = 0;
	while (num[0] < 100)
	{
		while (num[1] < 100)
		{
			if (num[0] < num[1])
			{
				ft_putchar(num[0] / 10 + '0');
				ft_putchar(num[0] % 10 + '0');
				ft_putchar(' ');
				ft_putchar(num[1] / 10 + '0');
				ft_putchar(num[1] % 10 + '0');
				if (num[0] != 98 || num[1] != 99)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
			num[1]++;
		}
		num[0]++;
		num[1] = 0;
	}
}
