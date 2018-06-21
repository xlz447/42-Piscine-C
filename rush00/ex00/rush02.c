/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:05:14 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/19 17:55:49 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i <= y)
	{
		while (j <= x)
		{
			if ((i == 1 && j == 1) || (i == 1 && j == x))
				ft_putchar('A');
			else if ((i == y && j == 1) || (i == y && j == x))
				ft_putchar('C');
			else if ((i > 1 && i < y) && (j > 1 && j < x))
				ft_putchar(' ');
			else
				ft_putchar('B');
			j++;
		}
		i++;
		j = 1;
		ft_putchar('\n');
	}
}
