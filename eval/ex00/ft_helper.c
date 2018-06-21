/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 20:04:40 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/03 00:44:39 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str = str + 1;
	}
	return (count);
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

char	*remove_space(char *in)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	out = (char*)malloc(sizeof(*out) * (ft_strlen(in) + 1));
	while (in[i] != '\0')
	{
		if (in[i] != ' ')
		{
			out[j] = in[i];
			j++;
		}
		i++;
	}
	out[j] = '\0';
	return (out);
}
