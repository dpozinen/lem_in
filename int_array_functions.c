/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:44:30 by dpozinen          #+#    #+#             */
/*   Updated: 2018/06/01 16:44:31 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*make_int_arr(int size, int num)
{
	int *ret;
	int i;

	MALCHK((ret = (int*)malloc(sizeof(int) * size)));
	i = 0;
	while (i < size)
	{
		ret[i] = num;
		i++;
	}
	return (ret);
}

int		find_int_in_arr(int i, int *arr, int size)
{
	int c;

	c = 0;
	while (c < size)
	{
		if (arr[c] == i)
			return (1);
		c++;
	}
	return (0);
}

int		max_int_arr(int *arr, int size)
{
	int i;
	int max;

	i = 0;
	max = arr[i];
	while (i < size)
	{
		if (max < arr[i])
			max = arr[i];
		i++;
	}
	return (max);
}

int		sum_int_array(int *array, int size)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (i < size)
	{
		sum += array[i];
		i++;
	}
	return (sum);
}

int		find_min_index(int *arr, int size)
{
	int i;
	int min_index;
	int min;

	i = 0;
	min_index = 0;
	min = arr[0];
	while (i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int		*intdup(int *arr, int size)
{
	int *ret;
	int i;

	i = 0;
	MALCHK((ret = (int*)malloc(sizeof(int) * size)));
	while (i < size)
	{
		ret[i] = arr[i];
		i++;
	}
	return (ret);
}
