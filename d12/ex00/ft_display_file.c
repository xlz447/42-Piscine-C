/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:58:38 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/30 18:58:40 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	main(int argc, char *argv[])
{
	char	buffer[BUFFER_SIZE];
	int		fd;
	int		ret;

	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else if (argc < 2)
		write(2, "File name missing.\n", 19);
	else
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			while ((ret = read(fd, buffer, BUFFER_SIZE)))
				write(1, buffer, ret);
			close(fd);
		}
	}
	return (0);
}
