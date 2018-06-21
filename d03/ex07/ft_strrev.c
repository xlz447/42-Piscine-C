/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:59:24 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/17 17:36:32 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		count;
	int		swap;
	char	temp;

	if (str[0] == '\0')
	{
		return (str);
	}
	count = 0;
	swap = 0;
	while (str[count + 1] != '\0')
	{
		count++;
	}
	while (swap < count)
	{
		temp = str[swap];
		str[swap] = str[count];
		str[count] = temp;
		swap++;
		count--;
	}
	return (str);
}
