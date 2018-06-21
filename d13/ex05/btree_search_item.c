/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 01:39:06 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/01 01:39:25 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *left;
	void *right;

	if (root == NULL)
		return (NULL);
	if (root->left)
	{
		left = btree_search_item(root->left, data_ref, cmpf);
		if (left)
			return (left);
	}
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (root->right)
	{
		right = btree_search_item(root->right, data_ref, cmpf);
		if (right)
			return (right);
	}
	return (NULL);
}
