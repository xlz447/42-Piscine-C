/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:25:37 by xzhu              #+#    #+#             */
/*   Updated: 2018/06/02 16:25:38 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H
# include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;

void				ft_list_push_back(t_list **begin_list, char *data);

#endif
