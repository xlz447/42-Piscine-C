/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 01:26:03 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/25 01:30:19 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H

# define FT_PERSO_H
# define SAVE_THE_WORLD "save 42"

# include <string.h>

typedef struct	s_perso {
	char	*name;
	double	life;
	int		age;
	char	*profession;
}				t_perso;

#endif
