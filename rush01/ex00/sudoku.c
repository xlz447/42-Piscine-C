/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:42:55 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/27 17:38:46 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		**intput_to_intarray(char *argv[])
{
	int **out;
	int i;
	int j;

	i = 0;
	j = 0;
	out = (int**)malloc(sizeof(*out) * 9);
	while (i < 9)
	{
		out[i] = (int*)malloc(sizeof(**out) * 9);
		while (argv[i + 1][j] != '\0')
		{
			if (argv[i + 1][j] != '.')
				out[i][j] = argv[i + 1][j] - '0';
			else
				out[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (out);
}

void	print_sudoku(int **in)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			c = in[i][j] + '0';
			write(1, &c, 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int		ft_guess_numbers(int **board, int row, int col, int **solution)
{
	int digit;

	digit = 0;
	while (++digit <= 9)
	{
		if (ft_is_available(board, row, col, digit))
		{
			board[row][col] = digit;
			if (row + 1 < 9)
				ft_sudoku(board, row + 1, col, solution);
			else if (col + 1 < 9)
				ft_sudoku(board, 0, col + 1, solution);
			else
			{
				copy_output(board, solution);
				g_success_count++;
				return (1);
			}
		}
	}
	board[row][col] = 0;
	return (0);
}

int		ft_sudoku(int **board, int row, int col, int **solution)
{
	if (g_success_count > 1)
		return (0);
	if (board[row][col] != 0)
	{
		if (row + 1 < 9)
			return (ft_sudoku(board, row + 1, col, solution));
		else if (col + 1 < 9)
			return (ft_sudoku(board, 0, col + 1, solution));
		else
		{
			copy_output(board, solution);
			g_success_count++;
			return (1);
		}
	}
	else
		return (ft_guess_numbers(board, row, col, solution));
}

int		main(int argc, char *argv[])
{
	int **input;
	int **solution;
	int i;

	i = 0;
	solution = (int**)malloc(sizeof(*solution) * 9);
	while (i < 9)
	{
		solution[i] = (int*)malloc(sizeof(**solution) * 9);
		i++;
	}
	if (input_check(argc, argv))
	{
		g_success_count = 0;
		input = intput_to_intarray(argv);
		ft_sudoku(input, 0, 0, solution);
		if (g_success_count == 1)
		{
			print_sudoku(solution);
			return (0);
		}
	}
	write(1, "Error\n", 6);
	return (0);
}
