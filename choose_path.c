/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:04:42 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/30 13:04:43 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		intersect(int *arr1, int *arr2, int size, int end)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (find_int_in_arr(arr1[i], arr2, size) && arr1[i] != end)
			return (1);
		i++;
	}
	return (0);
}



int		choose_paths(t_main *lem)
{

}