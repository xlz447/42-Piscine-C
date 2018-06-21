/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 02:13:12 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/01 02:13:13 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int leftc;
	int rightc;

	if (!root)
		return (0);
	leftc = btree_level_count(root->left);
	rightc = btree_level_count(root->right);
	if (leftc > rightc)
		return (1 + leftc);
	else
		return (1 + rightc);
}
