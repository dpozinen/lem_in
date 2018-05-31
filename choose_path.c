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

/*
int		get_efficiency(int *set, int ants, t_path *path)//ants+links-1
{
	int path1;
	int path2;
	int min;
	int holder_p1;
	int holder_p2;
	int holder_p3;

	path2 = 0;
	min = 0;
	while (path2 <= ants)
	{
		path1 = 0;
		holder_p3 = path2 + get_path_length(path, set[2]) - 1;
		while (path1 <= ants - path2)
		{
			holder_p1 = path1 + get_path_length(path, set[0]) - 1;
			holder_p2 = ants - path1 - path2 + get_path_length(path, set[1]) - 1;
			
			int c = max_3(holder_p1, holder_p2, holder_p3);
			min == 0 ? min = c : 0;
			if (min > c)
				min = c;
			
			
			// printf("min = %d; holder_p1 = %d; holder_p2 = %d; holder3 = %d\n", min, holder_p1, holder_p2, holder_p3);
			if (c == 11)
				printf("path2 = %d; path1 = %d; c = %d\n\n", path1, path2, c);
			path1++;
		}
		path2++;
	}
	return (min);
}
*/

int		intersect(int *arr1, int *arr2, int size, int end)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (find_int_in_arr(arr1[i], arr2, size) && arr1[i] != end)
			return (1);
		i++;
	}
	return (0);
}

int		get_min_path(t_path *path)
{
	int min;

	min = path->length;
	while (path)
	{
		if (min > path->length)
			min = path->length;
		path = path->next;
	}
	return (min);
}

int		get_path_length(t_path *path, int name)
{
	while (path)
	{
		if (name == path->name)
			return (path->length);
		path = path->next;
	}
	return (0);
}

int max_3(int a, int b, int c)
{
	if (a >= b)
		if (a >= c)
			return (a);
	if (b >= a)
		if (b >= c)
			return (b);
	return (c);
}

int		make_set(int set_n, t_main *lem)
{
	(void)lem;
	(void)set_n;
	return (0);
}

int		choose_paths(t_main *lem)
{
	int		set_n;
	int		min;
	// int		holder;
	int		*sets;

	set_n = 2;
	MALCHK((sets = init_path(lem->paths)));
	// while (1)
	// {
	// 	holder = make_best_set(set_n, lem);
	// 	if (min > holder)
	// 	{
	// 		min = holder;
	// 		set_n++;
	// 	}
	// 	else
	// 		return (1);
	// }
	return (0);
}
