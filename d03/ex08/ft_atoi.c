/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:34:46 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/17 18:51:36 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int result;
	int negative;

	result = 0;
	negative = 0;
	if (*str == '-')
	{
		negative = 1;
		str = str + 1;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		result = result * 10 + (*str - '0');
		str = str + 1;
	}
	if (negative)
	{
		result *= -1;
	}
	return (result);
}
