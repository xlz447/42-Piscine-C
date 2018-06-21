/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 21:57:52 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/21 22:43:53 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				empty;
	char			*src_copy;

	src_copy = src;
	i = 0;
	while (*dest != '\0' && i < size)
	{
		dest++;
		i++;
	}
	empty = size - i;
	if (empty == 0)
		return (i + ft_strlen(src));
	while (*src_copy != '\0')
	{
		if (empty != 1)
		{
			*dest++ = *src_copy;
			empty--;
		}
		src_copy++;
	}
	*dest = '\0';
	return (i + (src_copy - src));
}
