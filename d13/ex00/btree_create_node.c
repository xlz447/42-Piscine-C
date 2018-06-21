/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:36:51 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/31 23:37:26 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *out;

	out = (t_btree*)malloc(sizeof(*out));
	if (!out)
		return (NULL);
	out->item = item;
	out->left = 0;
	out->right = 0;
	return (out);
}
