/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 22:58:21 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/24 23:17:58 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
{
	if ((i >= j && i <= k) || (i <= j && i >= k))
		return (i);
	else if ((j >= i && j <= k) || (j <= i && j >= k))
		return (j);
	else if ((k >= j && k <= i) || (k <= j && k >= i))
		return (k);
	return (0);
}
