/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:36:19 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/17 21:25:50 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void ft_print_combn(int n);


int		ft_putchar(char c);

int x = 0;

void	ft_print_combn(int n)
{
printf("%d",n);

	if (n > 1) {
		printf("%d",x);
		x++;
	}else{
		n--;
		ft_print_combn(n);
	}
}

int main(void){
	ft_print_combn(5);
	return(0);
}

