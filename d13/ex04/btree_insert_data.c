/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 00:13:36 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/01 00:13:38 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree *tree;

	if (!root || !*root || !item)
	{
		if (item && root)
			*root = btree_create_node(item);
		return ;
	}
	tree = *root;
	if (cmpf(tree->item, item) > 0)
	{
		if (tree->left)
			btree_insert_data(&tree->left, item, cmpf);
		else
			tree->left = btree_create_node(item);
	}
	else
	{
		if (tree->right)
			btree_insert_data(&tree->right, item, cmpf);
		else
			tree->right = btree_create_node(item);
	}
}
