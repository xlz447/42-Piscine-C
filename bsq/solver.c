/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:44:49 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/06 10:44:52 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

char			next_element(void)
{
	char	curr;
	t_list	*to_del;

	while (g_head)
	{
		if (g_head->len == 0)
		{
			to_del = g_head;
			g_head = g_head->next;
			free(to_del);
		}
		curr = g_head->buf[g_head->cursor];
		g_head->cursor++;
		g_head->len--;
		if (curr == g_symb[0])
			return (1);
		else if (curr == g_symb[1])
			return (0);
	}
	return (42);
}

void			solve_helper(unsigned short **table, unsigned int matrix_index,
					unsigned short *max, unsigned int *max_index)
{
	unsigned short x;
	unsigned short y;
	unsigned short z;

	x = 0;
	y = 0;
	z = 0;
	if (matrix_index >= g_line_len && (matrix_index % g_line_len))
	{
		x = (*table)[matrix_index - g_line_len - 1];
		y = (*table)[matrix_index - g_line_len];
		z = (*table)[matrix_index - 1];
	}
	if (x <= y && x <= z)
		(*table)[matrix_index] = 1 + x;
	else if (y <= x && y <= z)
		(*table)[matrix_index] = 1 + y;
	else
		(*table)[matrix_index] = 1 + z;
	if ((*table)[matrix_index] > *max)
	{
		*max = (*table)[matrix_index];
		*max_index = matrix_index;
	}
}

void			print_sol_helper(unsigned int *i, unsigned int *j,
					char **to_print)
{
	if (*i % g_line_len == (g_line_len - 1))
		(*to_print)[++(*j)] = '\n';
	(*i)++;
	(*j)++;
}

void			print_solution(unsigned short *table, unsigned short max,
					unsigned int max_index)
{
	unsigned int	v[2];
	unsigned int	num_fill;
	char			*to_print;

	to_print = (char*)malloc((g_line_len + 1) * g_line_num);
	v[0] = 0;
	v[1] = 0;
	num_fill = ((unsigned int)max) * ((unsigned int)max);
	while (v[0] < g_line_len * g_line_num)
	{
		if (num_fill && (v[0] >= max_index - (max - 1) * (g_line_len + 1)) &&
		(v[0] % g_line_len >= (max_index - max + 1) % g_line_len) &&
		(v[0] % g_line_len <= max_index % g_line_len))
		{
			num_fill--;
			to_print[v[1]] = g_symb[2];
		}
		else if (table[v[0]] == 0)
			to_print[v[1]] = g_symb[1];
		else
			to_print[v[1]] = g_symb[0];
		print_sol_helper(&v[0], &v[1], &to_print);
	}
	write(1, to_print, (g_line_len + 1) * g_line_num);
	free(to_print);
}

void			solve(void)
{
	char			next;
	unsigned short	*table;
	unsigned int	matrix_index;
	unsigned short	max;
	unsigned int	max_index;

	table = (unsigned short*)malloc(sizeof(unsigned short)
			* g_line_len * g_line_num);
	matrix_index = 0;
	max = 0;
	while (matrix_index < (g_line_len * g_line_num))
	{
		next = next_element();
		if (matrix_index < g_line_len || !(matrix_index % g_line_len))
			table[matrix_index] = next;
		if (next == 1)
			solve_helper(&table, matrix_index, &max, &max_index);
		else if (next == 0)
			table[matrix_index] = 0;
		matrix_index++;
	}
	print_solution(table, max, max_index);
	free(table);
}
