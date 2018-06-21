/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 03:17:26 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/25 03:21:07 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int temp;

	if (size > 1)
	{
		j = 0;
		while (j < size - 1)
		{
			i = j + 1;
			while (i < size)
			{
				if (tab[j] > tab[i])
				{
					temp = tab[j];
					tab[j] = tab[i];
					tab[i] = temp;
				}
				i++;
			}
			j++;
		}
	}
}

int		ft_unmatch(int *tab, int length)
{
	int i;

	i = 0;
	ft_sort_integer_table(tab, length);
	while (i < length - 1)
	{
		if (tab[i] == tab[i + 1])
			i = i + 2;
		else
			return (tab[i]);
	}
	return (tab[length - 1]);
}
