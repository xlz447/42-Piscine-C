/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:17:54 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/20 22:34:32 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		g_total_col;
int		g_total_row;
int		g_door_size;
int		g_var[5];

void	get_size(int size)
{
	int size_count[2];
	int current_block;
	int block_size;
	int current_size;

	current_block = 0;
	block_size = 3;
	current_size = 0;
	size_count[0] = 1;
	size_count[1] = 0;
	while (current_block < size)
	{
		while (current_size < block_size)
		{
			current_size++;
			size_count[0] += 2;
			size_count[1]++;
		}
		g_total_col = size_count[0];
		size_count[0] = size_count[0] + 4 + 2 * (current_block / 2);
		current_size = 0;
		block_size++;
		current_block++;
	}
	g_total_row = size_count[1];
}

int		get_white_count(int total_row)
{
	while (g_var[1] < total_row)
	{
		if (g_var[0])
		{
			g_var[4] = g_var[4] + 6 + 2 * ((g_var[3] - 3) / 2);
			g_var[0] = 0;
			g_var[3]++;
		}
		else
			g_var[4] += 2;
		if (g_var[2] == g_var[3])
		{
			g_var[1]++;
			g_var[2] = 1;
			g_var[0] = 1;
		}
		else
		{
			g_var[1]++;
			g_var[2]++;
		}
	}
	return (g_var[4]);
}

void	put_str(int num, char c)
{
	int i;

	i = 0;
	while (i < num)
	{
		ft_putchar(c);
		i++;
	}
}

void	print_door(int current_row)
{
	int row;
	int knob_offset;

	knob_offset = g_door_size - (g_door_size + 1) / 2;
	row = 0;
	while (row < g_door_size)
	{
		put_str((g_total_col - get_white_count(current_row)) / 2, ' ');
		ft_putchar(47);
		put_str((get_white_count(current_row) - 2 - g_door_size) / 2, '*');
		if (g_door_size >= 5 && row == knob_offset)
		{
			put_str(g_door_size - 2, '|');
			ft_putchar('$');
			ft_putchar('|');
		}
		else
			put_str(g_door_size, '|');
		put_str((get_white_count(current_row) - 2 - g_door_size) / 2, '*');
		ft_putchar(92);
		ft_putchar('\n');
		current_row++;
		row++;
	}
}

void	sastantua(int size)
{
	int level;
	int row;
	int white;

	g_var[0] = 0;
	g_var[1] = 0;
	g_var[2] = 1;
	g_var[3] = 3;
	g_var[4] = 1;
	white = 3;
	level = 0;
	row = 1;
	g_door_size = size + (size % 2 - 1);
	get_size(size);
	while (row <= g_total_row - g_door_size)
	{
		put_str((g_total_col - get_white_count(row)) / 2, ' ');
		ft_putchar(47);
		put_str(get_white_count(row) - 2, '*');
		ft_putchar(92);
		ft_putchar('\n');
		row++;
	}
	print_door(row);
}
