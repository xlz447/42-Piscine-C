/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 00:10:29 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/25 00:50:59 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*found;
	int		val[3];

	val[0] = 0;
	val[1] = 0;
	if (*to_find == '\0')
		return (str);
	while (str[val[1]] != '\0')
	{
		val[2] = val[1];
		while (to_find[val[0]] == str[val[2]])
		{
			if (to_find[val[0] + 1] == '\0')
			{
				found = &str[val[1]];
				return (found);
			}
			val[0]++;
			val[2]++;
		}
		val[0] = 0;
		val[1]++;
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str = str + 1;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		if (ft_strstr(ft_strlowcase(argv[i]), "president") ||
			ft_strstr(ft_strlowcase(argv[i]), "attack") ||
			ft_strstr(ft_strlowcase(argv[i]), "bauer"))
			flag = 1;
		i++;
	}
	if (flag)
	{
		ft_putstr("Alert!!!");
		ft_putchar('\n');
	}
	return (0);
}
