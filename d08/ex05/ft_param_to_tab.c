/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 03:41:29 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/25 04:27:03 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
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

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char				*ft_strdup(char *src)
{
	char *str;

	str = (char*)malloc(sizeof(*str) * (ft_strlen(src) + 1));
	if (!str)
		return (str);
	else
		return (ft_strcpy(str, src));
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *out;
	int			i;

	i = 0;
	out = (t_stock_par*)malloc(sizeof(*out) * (ac + 1));
	while (i < ac)
	{
		out[i].size_param = ft_strlen(av[i]);
		out[i].str = av[i];
		out[i].copy = ft_strdup(av[i]);
		out[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	out[i].str = 0;
	return (out);
}
