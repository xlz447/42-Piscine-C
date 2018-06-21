/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 03:15:47 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/06 07:08:13 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

char		read_file(char *filename)
{
	short				fd;
	short				rd;
	t_list				*current;

	if ((fd = open(filename, O_RDONLY)) >= 0)
	{
		ft_list_push_back(&g_head, 0);
		current = g_head;
		while ((rd = read(fd, (current->buf + current->cursor), BUF_SIZE)))
		{
			current->cursor += rd;
			current->len += rd;
			current->buf[current->cursor] = '\0';
			if (current->cursor + BUF_SIZE > BUF_SIZE)
			{
				current->cursor = 0;
				ft_list_push_back(&current, current->index + 1);
				current = current->next;
			}
			if (rd < BUF_SIZE)
				current->cursor = 0;
		}
		return (close(fd) + 1);
	}
	return (-15);
}

char		read_stdin_1st(void)
{
	t_list				*current;

	ft_list_push_back(&g_head, 0);
	current = g_head;
	while (read(0, (current->buf + current->cursor), 1))
	{
		if (current->cursor > 14)
			return (-7);
		if (*(current->buf + current->cursor) == '\n')
			break ;
		current->cursor++;
	}
	if (!current->buf[0])
		return (-33);
	g_symb[0] = current->buf[current->cursor - 3];
	g_symb[1] = current->buf[current->cursor - 2];
	g_symb[2] = current->buf[current->cursor - 1];
	if (g_symb[0] == g_symb[1] || g_symb[1] == g_symb[2] ||
		g_symb[0] == g_symb[2])
		return (-42);
	current->buf[current->cursor - 3] = '\0';
	g_line_num = my_atoi(current->buf);
	current->cursor = 0;
	free(g_head);
	return (42);
}

void		read_stdin_2nd(void)
{
	short				rd;
	t_list				*current;

	g_head = NULL;
	ft_list_push_back(&g_head, 0);
	current = g_head;
	while ((rd = read(0, (current->buf + current->cursor), BUF_SIZE)) > 0)
	{
		current->cursor += rd;
		current->len += rd;
		current->buf[current->cursor] = '\0';
		if (current->cursor + BUF_SIZE > BUF_SIZE)
		{
			current->cursor = 0;
			ft_list_push_back(&current, current->index + 1);
			current = current->next;
		}
	}
	current->cursor = 0;
}

void		read_stdin_line_len(void)
{
	unsigned short		i;
	unsigned short		j;
	t_list				*current;

	current = g_head;
	i = 0;
	j = 0;
	while (42)
	{
		if (*(current->buf + current->cursor + j) == '\n')
			break ;
		if (j < current->len - 1)
			j++;
		else
		{
			j = 0;
			current = current->next;
		}
		i++;
	}
	g_line_len = i;
}
