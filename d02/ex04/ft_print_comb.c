/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:44:08 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/17 18:59:15 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb(void)
{
	int xyz[3];

	xyz[0] = 0;
	while (xyz[0] <= 7)
	{
		xyz[1] = xyz[0] + 1;
		while (xyz[1] <= 8)
		{
			xyz[2] = xyz[1] + 1;
			while (xyz[2] <= 9)
			{
				ft_putchar(xyz[0] + '0');
				ft_putchar(xyz[1] + '0');
				ft_putchar(xyz[2] + '0');
				if (xyz[0] + xyz[1] + xyz[2] != 24)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				xyz[2]++;
			}
			xyz[1]++;
		}
		xyz[0]++;
	}
}
