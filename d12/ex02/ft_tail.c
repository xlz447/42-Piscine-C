/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:24:56 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/31 14:24:58 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		special_atoi(char *str)
{
	int result;
	int	space;

	result = 0;
	space = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
		*str == '\f' || *str == '\r' || *str == ' ')
	{
		str++;
		space = 1;
	}
	if (*str == '-' || *str == '+')
	{
		atoi_mode_helper(*str, space);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str)
		g_atoi_mode = 2;
	return (result * g_atoi_mode);
}

int		file_size(int fd)
{
	int		size;
	char	buffer[1];

	size = 0;
	while (read(fd, buffer, 1))
	{
		size++;
	}
	close(fd);
	return (size);
}

void	normal_help(char *filename)
{
	write(2, "tail: ", 6);
	write(2, filename, ft_strlen(filename));
	if (errno == 13)
		write(2, ": Permission denied\n", 20);
	if (errno == 2)
		write(2, ": No such file or directory\n", 28);
}

void	normal(char *filename, int offset, int fd)
{
	char	buffer[1];
	int		val[3];

	val[1] = 1;
	if ((fd >= 0 && g_atoi_mode != 0))
	{
		if (offset >= 0 && g_atoi_mode != -1)
		{
			val[2] = file_size(fd);
			fd = open(filename, O_RDWR);
			while (val[1] < val[2] - offset + 1 && read(fd, buffer, 1))
				val[1]++;
			while ((val[0] = read(fd, buffer, 1)))
				write(1, buffer, val[0]);
		}
		else
		{
			while (val[1] < offset * -1 && read(fd, buffer, 1))
				val[1]++;
			while ((val[0] = read(fd, buffer, 1)))
				write(1, buffer, val[0]);
		}
	}
	else if (errno == 13 || errno == 2)
		normal_help(filename);
}

int		main(int argc, char *argv[])
{
	char	c;
	int		offset;

	g_atoi_mode = 1;
	if (argc > 2)
		offset = special_atoi(argv[2]);
	if (argc < 3)
		tail_helper(1, "lol", 1);
	else if (argc == 3 || g_atoi_mode == 2)
	{
		write(2, "tail: illegal offset -- ", 24);
		write(2, argv[2], ft_strlen(argv[2]));
		write(2, "\n", 1);
	}
	else if (argc == 3)
		while (read(0, &c, 1) > 0)
			;
	else
		tail(argc, argv, offset);
	return (0);
}
