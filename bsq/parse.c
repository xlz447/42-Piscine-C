/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 03:10:54 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/06 03:10:58 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int		my_atoi(char *str)
{
	unsigned short		curr;
	int					result;

	curr = 0;
	result = 0;
	while (str[curr] != '\0')
	{
		if (str[curr] >= '0' && str[curr] <= '9')
			result = result * 10 + (str[curr] - '0');
		else
			return (-42);
		curr++;
	}
	return (result);
}

char				get_grid_helper(t_list **current)
{
	unsigned short		i;
	unsigned short		j;

	i = 0;
	j = 0;
	while (42)
	{
		if (!(*current)->buf[(*current)->cursor])
			return (-37);
		if (*((*current)->buf + (*current)->cursor + j) == '\n')
			break ;
		if (j < (*current)->len - 1)
			j++;
		else
		{
			j = 0;
			(*current) = (*current)->next;
		}
		i++;
	}
	g_line_len = i;
	return (42);
}

char				get_grid_dimensions(void)
{
	unsigned short		i;
	t_list				*current;

	current = g_head;
	i = 0;
	if (!current->buf[i])
		return (-33);
	while (current->buf[i] != '\n' && i < current->len)
		i++;
	if (i > 14)
		return (-21);
	g_symb[0] = current->buf[i - 3];
	g_symb[1] = current->buf[i - 2];
	g_symb[2] = current->buf[i - 1];
	if (g_symb[0] == g_symb[1] || g_symb[1] == g_symb[2] ||
		g_symb[0] == g_symb[2])
		return (-42);
	current->buf[i - 3] = '\0';
	if ((g_line_num = my_atoi(current->buf)) <= 0)
		return (-36);
	current->cursor = i + 1;
	current->len -= (i + 1);
	if (get_grid_helper(&current) < 0)
		return (-37);
	return (42);
}

char				check_input_helper(char to_check,
			unsigned short *curr_line_count, unsigned short *curr_line_len)
{
	if (to_check != g_symb[0] && to_check != g_symb[1]
		&& to_check != '\n' && to_check != '\0')
		return (-84);
	if (to_check != '\n' && to_check != '\0')
		(*curr_line_len)++;
	else if (to_check == '\n')
	{
		if (*curr_line_len != g_line_len)
			return (-42);
		(*curr_line_count)++;
		*curr_line_len = 0;
	}
	return (42);
}

char				check_input(void)
{
	unsigned short		j;
	unsigned short		curr_line_count;
	unsigned short		curr_line_len;
	t_list				*current;
	char				to_check;

	current = g_head;
	curr_line_len = 0;
	curr_line_count = 0;
	j = 0;
	while (current)
	{
		to_check = *(current->buf + current->cursor + j);
		if (check_input_helper(to_check, &curr_line_count, &curr_line_len) < 0)
			return (-42);
		if (j < current->len - 1)
			j++;
		else
		{
			j = 0;
			current = current->next;
		}
	}
	return (curr_line_count == g_line_num);
}
