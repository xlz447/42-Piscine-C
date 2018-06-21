/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:54:02 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/03 18:54:04 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_op(char c)
{
	if (c == '/' || c == '*' || c == '%')
		return (3);
	else if (c == '+' || c == '-')
		return (2);
	else if (c == '(' || c == ')')
		return (1);
	else if (c >= '0' && c <= '9')
		return (0);
	else
		return (-42);
}

long long	ft_atoi(char *str)
{
	long long	result;
	int			negative;

	result = 0;
	negative = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
		*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * (long long)negative);
}

char		*ft_itoa(long long nb)
{
	long long	val[3];
	char		*out;

	val[2] = 0;
	val[1] = 1;
	if (nb < 0 && val[1]++)
	{
		if (nb == -2147483648)
			return ("-2147483648");
		nb *= -1;
		val[2] = 1;
	}
	val[0] = nb;
	while ((val[0] /= 10) > 0)
		val[1]++;
	out = (char*)malloc(sizeof(*out) * (val[1] + 1));
	out[val[1]] = '\0';
	while (val[1]-- >= 1)
	{
		out[val[1]] = (nb % 10) + '0';
		nb /= 10;
	}
	if (val[2])
		out[0] = '-';
	return (out);
}

char		*do_op(char *first, char *third, char *op)
{
	long long a;
	long long b;
	long long out;

	a = ft_atoi(first);
	b = ft_atoi(third);
	if (op[0] == '+')
		out = a + b;
	if (op[0] == '-')
		out = a - b;
	if (op[0] == '*')
		out = a * b;
	if (op[0] == '/')
		out = a / b;
	if (op[0] == '%')
		out = a % b;
	return (ft_itoa((int)out));
}
