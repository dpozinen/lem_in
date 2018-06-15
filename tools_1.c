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
