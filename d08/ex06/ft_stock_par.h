/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 03:43:49 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/25 04:46:45 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

# include <stdlib.h>

typedef struct		s_stock_par
{
	int				size_param;
	char			*str;
	char			*copy;
	char			**tab;
}					t_stock_par;

char				**ft_split_whitespaces(char *str);
void				ft_show_tab(struct s_stock_par *par);
int					ft_strlen(char *str);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, char *src);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);
#endif
