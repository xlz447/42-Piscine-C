/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 15:18:52 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/02 15:23:01 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		get_token_size(char *in)
{
	int			i;

	i = 0;
	if (is_op(in[i]) == 1)
	{
		if (in[i] == '(')
			g_op_flag = 1;
		else if (in[i] == ')')
			g_op_flag = 0;
		return (1);
	}
	if (is_op(in[i]) > 1)
	{
		if (g_op_flag)
			i++;
		else
		{
			g_op_flag = 1;
			return (1);
		}
	}
	while (is_op(in[i]) == 0 && in[i] != '\0')
		i++;
	g_op_flag = 0;
	return (i);
}

char	*get_token(char **in, int token_size)
{
	char	*out;
	int		i;

	i = 0;
	out = (char*)malloc(sizeof(*out) * (token_size + 1));
	while (i < token_size)
	{
		out[i] = **in;
		i++;
		*in = *in + 1;
	}
	out[token_size] = '\0';
	return (out);
}

void	get_rpn(t_list **llist, t_stack **stack, char *token, int token_size)
{
	if (token_size > 1 || is_op(token[0]) == 0)
		ft_list_push_back(llist, token);
	else
	{
		if (is_op(token[0]) == 2)
		{
			while (is_op(peek(*stack)) > 1)
				ft_list_push_back(llist, pop(stack));
			push(stack, *token);
		}
		if (is_op(token[0]) == 3)
		{
			while (is_op(peek(*stack)) == 3)
				ft_list_push_back(llist, pop(stack));
			push(stack, *token);
		}
		if (token[0] == '(')
			push(stack, *token);
		if (token[0] == ')')
		{
			while (peek(*stack) != '(')
				ft_list_push_back(llist, pop(stack));
			pop(stack);
		}
	}
}

void	eval_rpn(t_list **llist)
{
	t_list	*copy;

	copy = *llist;
	while (copy->next)
	{
		if ((ft_strlen(copy->data) > 1 || is_op(copy->data[0]) == 0) &&
			(ft_strlen(copy->next->data) > 1 || is_op(copy->next->data[0]) == 0)
			&& (is_op(copy->next->next->data[0]) > 1
			&& copy->next->next->data[1] == '\0'))
		{
			copy->data = do_op(copy->data, copy->next->data,
						copy->next->next->data);
			copy->next = copy->next->next->next;
			copy = *llist;
		}
		else
			copy = copy->next;
	}
}

int		eval_expr(char *in)
{
	int		token_size;
	char	*token;
	t_list	*llist;
	t_stack	*stack;

	llist = NULL;
	stack = NULL;
	in = remove_space(in);
	while (*in != '\0')
	{
		token_size = get_token_size(in);
		token = get_token(&in, token_size);
		get_rpn(&llist, &stack, token, token_size);
	}
	while (stack)
		ft_list_push_back(&llist, pop(&stack));
	eval_rpn(&llist);
	return (ft_atoi(llist->data));
}
