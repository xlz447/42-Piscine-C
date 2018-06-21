/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:45:56 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/21 23:43:25 by xzhu             ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	new_size;
	unsigned int	src_size;

	src_size = ft_strlen(src);
	if (!size)
		return (src_size);
	if (src_size >= size)
		new_size = size - 1;
	else
		new_size = src_size;
	while (new_size > 0)
	{
		*dest = *src;
		dest++;
		src++;
		new_size--;
	}
	*dest = '\0';
	return (src_size);
}
