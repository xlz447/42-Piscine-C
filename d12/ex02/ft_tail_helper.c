/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:30:25 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/31 15:31:00 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail_helper.h"

void	atoi_mode_helper(char c, int space)
{
	if (c == '-' && space)
		g_atoi_mode = 0;
	else if (c == '+' && !space)
		g_atoi_mode = -1;
}

int		ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

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

void	tail_helper(int head_flag, char *argv, int print_use)
{
	if (print_use)
	{
		write(2, "tail: option requires an argument -- c\n", 39);
		write(2, "usage: tail [-F | -f | -r] [-q] [-b # |", 39);
		write(2, " -c # | -n #] [file ...]\n", 25);
	}
	else
	{
		if (head_flag && errno != 2 && errno != 13)
		{
			write(1, "==> ", 4);
			write(1, argv, ft_strlen(argv));
			write(1, " <==\n", 5);
		}
	}
}

void	tail(int argc, char *argv[], int offset)
{
	int i;
	int head_flag;
	int fd;
	int print_newline;

	i = 3;
	head_flag = 0;
	print_newline = 0;
	if (argc > 4)
		head_flag = 1;
	while (argv[i])
	{
		fd = open(argv[i], O_RDWR);
		if (head_flag && errno != 2 && errno != 13 && print_newline)
		{
			write(1, "\n", 1);
			print_newline = 0;
		}
		tail_helper(head_flag, argv[i], 0);
		normal(argv[i], offset, fd);
		if (errno != 2 && errno != 13)
			print_newline = 1;
		close(fd);
		i++;
	}
}
