/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:41:12 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/17 18:55:16 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char current_char;

	current_char = 'a';
	while (current_char <= 'z')
	{
		ft_putchar(current_char);
		current_char += 1;
	}
}
