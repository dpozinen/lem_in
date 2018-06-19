/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:10:18 by dpozinen          #+#    #+#             */
/*   Updated: 2018/06/08 18:10:18 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_other_paths(int *arr, int worst, int size, int n_of_paths)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] >= worst)
			c++;
		if ((c >= 2 && n_of_paths >= 2) || (c == 1 && n_of_paths == 1))
			return (1);
		i++;
	}
	return (0);
}

static void	increment(int *path_congestion, int *lengths)
{
	(*path_congestion)++;
	(*lengths)++;
}

int			get_efficiency(int *lengths, int n_of_paths,
							int ants, int *path_congestion)
{
	int		worst;
	int		i;
	int		ants_sum;

	if (n_of_paths == 1 && lengths[0] == 1 && (path_congestion[0] = ants))
		return (1);
	worst = max_int_arr(lengths, n_of_paths);
	ants_sum = sum_int_array(path_congestion, n_of_paths);
	while (ants_sum < ants)
	{
		i = 0;
		while (i < n_of_paths && ants_sum < ants)
		{
			if (lengths[i] < worst || lengths[i] > worst)
				increment(&path_congestion[i], &lengths[i]);
			else if (lengths[i] == worst &&
					check_other_paths(lengths, worst, n_of_paths, n_of_paths))
				increment(&path_congestion[i], &lengths[i]);
			ants_sum = sum_int_array(path_congestion, n_of_paths);
			i++;
		}
	}
	return (max_int_arr(lengths, n_of_paths));
}

/*
** goes through each room in existance
** path_arr[i] is the id of the room in the path
** room_arr[path_arr[i]] is the room in the whole array of rooms,
** we increment it to mark visited room
*/

static int	fill_path_rooms(int *room_arr, t_path *path, int start, int end)
{
	int	*path_arr;
	int	i;

	path_arr = path->path;
	i = 0;
	while (i < path->length)
	{
		(room_arr[path_arr[i]])++;
		if (path_arr[i] != end && path_arr[i] != start)
			if (room_arr[path_arr[i]] >= 2)
				return (0);
		i++;
	}
	return (1);
}

int			set_intersect(t_path **path_arr, int set_n, t_main *lem)
{
	int		*room_arr;
	int		i;
	int		set;
	t_path	*path;

	i = 0;
	MALCHK((room_arr = make_int_arr(lem->rooms, 0)));
	set = 0;
	while (set < set_n)
	{
		path = path_arr[set];
		if (!fill_path_rooms(room_arr, path, lem->istart, lem->iend))
		{
			free(room_arr);
			return (1);
		}
		set++;
	}
	free(room_arr);
	return (0);
}
