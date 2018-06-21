/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <xzhu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:46:59 by xzhu              #+#    #+#             */
/*   Updated: 2018/05/22 12:28:33 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*found;
	int		val[3];

	val[0] = 0;
	val[1] = 0;
	if (*to_find == '\0')
		return (str);
	while (str[val[1]] != '\0')
	{
		val[2] = val[1];
		while (to_find[val[0]] == str[val[2]])
		{
			if (to_find[val[0] + 1] == '\0')
			{
				found = &str[val[1]];
				return (found);
			}
			val[0]++;
			val[2]++;
		}
		val[0] = 0;
		val[1]++;
	}
	return (0);
}
