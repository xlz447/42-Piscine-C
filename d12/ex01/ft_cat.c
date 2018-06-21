/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:31:46 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/30 20:31:49 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

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

void	cat(char *argv)
{
	char	buffer[BUFFER_SIZE];
	int		fd;
	int		ret;

	fd = open(argv, O_RDWR);
	if (fd > 0)
	{
		while ((ret = read(fd, buffer, BUFFER_SIZE)))
			write(1, buffer, ret);
		close(fd);
	}
	else
	{
		write(2, "cat: ", 5);
		write(2, argv, ft_strlen(argv));
		if (errno == 21)
			write(2, ": Is a directory\n", 17);
		if (errno == 13)
			write(2, ": Permission denied\n", 20);
		if (errno == 2)
			write(2, ": No such file or directory\n", 28);
	}
}

void	std_input(void)
{
	char c;

	while (read(0, &c, 1) > 0)
		write(1, &c, 1);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc > 1)
	{
		if (argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2] == '\0')
			i++;
	}
	if (argc == i)
		std_input();
	else
	{
		while (argv[i])
		{
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				std_input();
			else
				cat(argv[i]);
			i++;
		}
	}
	return (0);
}
