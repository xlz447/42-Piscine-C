/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:50:32 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/18 11:59:01 by xzhu             ###   ########.fr       */
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
