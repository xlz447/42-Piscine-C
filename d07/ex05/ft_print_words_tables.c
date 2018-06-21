/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@students.42.us.org>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:21:24 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/24 16:09:00 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	if (str)
	{
		while (*str != '\0')
		{
			ft_putchar(*str);
			++str;
		}
		ft_putchar('\n');
	}
}

void	ft_print_words_tables(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i] != 0)
			ft_putstr(tab[i++]);
	}
}
