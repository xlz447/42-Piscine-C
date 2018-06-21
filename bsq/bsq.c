/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:02:26 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/04 14:02:32 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	help_main_stdin(void)
{
	if (read_stdin_1st() < 0 || g_line_num <= 0)
		write(2, "map error\n", 10);
	else
	{
		read_stdin_2nd();
		read_stdin_line_len();
		if (check_input() < 0)
			write(2, "map error\n", 10);
		else
			solve();
	}
}

void	help_main_file(char *filename)
{
	if (read_file(filename) < 0 ||
		get_grid_dimensions() < 0 ||
		check_input() <= 0)
		write(2, "map error\n", 10);
	else
		solve();
}

int		main(int argc, char **argv)
{
	unsigned short		i;

	g_head = NULL;
	if (argc <= 1)
		help_main_stdin();
	else
	{
		i = 1;
		while (i < argc)
		{
			if (i != 1)
				write(1, "\n", 1);
			help_main_file(argv[i]);
			i++;
			free(g_head);
			g_head = NULL;
		}
	}
	return (0);
}
