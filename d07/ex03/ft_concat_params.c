/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:33:31 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/23 19:33:18 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strcat(char *dest, char *src, int last_flag)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (*src != '\0')
	{
		dest[i] = *src;
		i++;
		src++;
	}
	if (!last_flag)
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		len;
	char	*str;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len = len + ft_strlen(argv[i]) + 1;
		i++;
	}
	str = (char*)malloc(sizeof(*str) * len);
	*str = '\0';
	i = 1;
	while (i < argc)
	{
		if (i == argc - 1)
			ft_strcat(str, argv[i], 1);
		else
			ft_strcat(str, argv[i], 0);
		i++;
	}
	return (str);
}
