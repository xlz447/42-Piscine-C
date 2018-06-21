/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:44:57 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/27 18:47:58 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H

# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

int		ft_is_available(int **board, int row, int col, int digit);
int		ft_sudoku(int **board, int row, int col, int **solution);
int		input_check(int argc, char *argv[]);
int		**intput_to_intarray(char *argv[]);
void	print_sudoku(int **in);
void	copy_output(int **board, int **solution);
int		g_success_count;
#endif
