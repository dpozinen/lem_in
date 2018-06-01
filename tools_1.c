/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:58:14 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/17 13:58:14 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		max_3(int a, int b, int c)
{
	if (a >= b)
		if (a >= c)
			return (a);
	if (b >= a)
		if (b >= c)
			return (b);
	return (c);
}

char	*ft_strchut(char *line, char c)
{
	char	*ret;
	int		i;
	int		size;

	size = get_char_index(line, c);
	if (!(ret = ft_strnew(size + 1)))
		return (0);
	i = 0;
	while (i < size)
	{
		ret[i] = line[i];
		i++;
	}
	return (ret);
}

int		**make_matrix(t_main *lem)
{
	int	**matrix;
	int i;
	int	j;

	MALCHK((matrix = (int**)malloc(sizeof(int*) * lem->rooms)));
	i = 0;
	while (i < lem->rooms)
	{
		MALCHK((matrix[i] = (int*)malloc(sizeof(int) * lem->rooms)));
		j = 0;
		while (j < lem->rooms)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}
