/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 03:35:49 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/06 03:35:53 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H

# define LINKEDLIST_H

# include <stdlib.h>
# include "global.h"

t_list		*ft_create_elem(unsigned short index);
void		ft_list_push_back(t_list **begin_list, unsigned short index);
void		ft_list_clear(t_list **begin_list);

#endif
