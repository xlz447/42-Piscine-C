/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:57:28 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/23 23:16:02 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str = str + 1;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s2 != '\0')
		return (*s1 - *s2);
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc > 2)
	{
		j = 1;
		while (j < argc - 1)
		{
			i = j + 1;
			while (i < argc)
			{
				if (ft_strcmp(argv[j], argv[i]) > 0)
				{
					ft_swap(&argv[j], &argv[i]);
				}
				i++;
			}
			ft_putstr(argv[j]);
			ft_putchar('\n');
			j++;
		}
		ft_putstr(argv[j]);
		ft_putchar('\n');
	}
}
