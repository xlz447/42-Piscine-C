/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:36:44 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/24 14:28:15 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ');
}

int		count_word(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (is_space(str[i]) && str[i] != '\0')
			i++;
		if (str[i] != '\0' && str[i] != '\0')
			j++;
		while (!is_space(str[i]) && str[i] != '\0')
			i++;
	}
	return (j);
}

int		append_output(int i, int j, char *str, char **out)
{
	int x;

	x = 0;
	while (!is_space(str[i]) && str[i] != '\0')
	{
		out[j][x] = str[i];
		i++;
		x++;
	}
	out[j][x] = '\0';
	return (i);
}

char	**ft_split_whitespaces(char *str)
{
	char	**out;
	int		word_count;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	word_count = count_word(str);
	out = (char**)malloc(sizeof(*out) * (word_count + 1));
	while (str[i] != '\0')
	{
		while (is_space(str[i]) && str[i] != '\0')
			i++;
		k = i;
		while (!is_space(str[k]) && str[k] != '\0')
			k++;
		out[j] = (char*)malloc(sizeof(**out) * (k - i + 1));
		i = append_output(i, j, str, out);
		if (j < word_count)
			j++;
	}
	out[j] = 0;
	return (out);
}
