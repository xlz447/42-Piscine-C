/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:15:27 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/22 10:15:47 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		check_base(char *base)
{
	int i;
	int j;

	j = 0;
	while (base[j] != '\0')
	{
		i = j + 1;
		if (base[j] == '+' || base[j] == '-' || base[j] < ' ' || base[j] > '~')
			return (-1);
		while (base[i] != '\0')
		{
			if (base[i] == base[j])
				return (-1);
			i++;
		}
		j++;
	}
	return (i);
}

void	print_base(int nbr, int length, char *base)
{
	if (nbr < length)
	{
		ft_putchar(base[nbr % length]);
	}
	else
	{
		print_base(nbr / length, length, base);
		ft_putchar(base[nbr % length]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int length;

	length = check_base(base);
	if (length > 1)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			print_base(nbr / (length * -1), length, base);
			ft_putchar(base[nbr % (length * -1)]);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			print_base(nbr * -1, length, base);
		}
		else
			print_base(nbr, length, base);
	}
}
