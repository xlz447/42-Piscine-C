/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:35:26 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/28 19:35:28 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include "ft_opp.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

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
		nb_size *= 10;
	while (nb_size > 0)
	{
		ft_putchar(nb / nb_size + '0');
		nb %= nb_size;
		nb_size /= 10;
	}
	ft_putchar('\n');
}

int		get_op(char *op)
{
	int	i;
	int	j;

	i = 0;
	while (g_opptab[i].op)
	{
		j = 0;
		while (op[j] && g_opptab[i].op[j] &&
				g_opptab[i].op[j] == op[j])
		{
			++j;
			if (!op[j])
				return (i);
		}
		++i;
	}
	return (-1);
}

int		do_op(int x, int y, int op)
{
	return ((*g_opptab[op].function)(x, y));
}

int		main(int argc, char *argv[])
{
	int op;

	if (argc != 4)
		return (0);
	op = get_op(argv[2]);
	if (op == -1)
		(*g_opptab[5].function)(0, 0);
	else if (op == 3 && ft_atoi(argv[3]) == 0)
		write(1, "Stop : division by zero\n", 24);
	else if (op == 4 && ft_atoi(argv[3]) == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		ft_putnbr(do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), op));
	return (0);
}
