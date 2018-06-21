/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:28:03 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/21 11:01:23 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int nb_copy;
	int nb_size;

	nb_size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb += 2000000000;
		}
		nb *= -1;
	}
	nb_copy = nb;
	while ((nb_copy /= 10) > 0)
	{
		nb_size *= 10;
	}
	while (nb_size > 0)
	{
		ft_putchar(nb / nb_size + '0');
		nb %= nb_size;
		nb_size /= 10;
	}
}
