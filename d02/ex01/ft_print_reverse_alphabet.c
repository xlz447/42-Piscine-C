/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:58:05 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/17 18:56:46 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	char current_char;

	current_char = 'z';
	while (current_char >= 'a')
	{
		ft_putchar(current_char);
		current_char -= 1;
	}
}
