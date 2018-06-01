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

/* int		get_efficiency_2(int *set, int ants, t_path *path)//ants+links-1
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
			holder_p2 =
				ants - path1 - path2 + get_path_length(path, set[1]) - 1;

			int c = max_3(holder_p1, holder_p2, holder_p3);
			min == 0 ? min = c : 0;
			if (min > c)
				min = c;
			if (c == 8)
			{
			 	printf("using top = %d; using middle = %d;
			using bottom = %d, c = %d\n", path2, path1, ants-path2-path1, c);
			 	printf("using top = %d; using middle = %d;
			using bottom = %d\n\n", holder_p3, holder_p1, holder_p2);
			}
			path1++;
		}
		path2++;
	}
	return (min);
} */

static void	increment(int *path_congestion, int *lengths)
{
	(*path_congestion)++;
	(*lengths)++;
}

int			get_efficiency(int *lengths, int n_of_paths, t_main *lem)
{
	int				worst;
	int				i;
	int				*path_congestion;
	unsigned int	ants_sum;

	worst = max_int_arr(lengths, n_of_paths);
	path_congestion = make_int_arr(n_of_paths, 1);
	ants_sum = sum_int_array(path_congestion, n_of_paths);
	while (ants_sum < lem->ants)
	{
		i = 0;
		while (i < n_of_paths && ants_sum < lem->ants)
		{
			if (ants_sum == lem->ants - 1)
				i = find_min_index(lengths, n_of_paths);
			if (lengths[i] < worst || lengths[i] > worst)
				increment(&path_congestion[i], &lengths[i]);
			else if (lengths[i] == worst &&
					check_other_paths(lengths, worst, n_of_paths))
				increment(&path_congestion[i], &lengths[i]);
			ants_sum = sum_int_array(path_congestion, n_of_paths);
			i++;
		}
	}
	return (max_int_arr(lengths, n_of_paths));
}

// int			make_best_set(t_main *lem)
// {

// 	return (0);
// }

int			choose_paths(t_main *lem)
{
	(void)lem;
// 	int		set_n;
// 	int		min;
// 	int		*lengths;
// 	int		*set;

// 	set_n = 2;

/* 	MALCHK((set = make_int_arr(lem->paths, 0)));
	set[0] = 10;
	set[1] = 15;
	set[2] = 3;
	printf("ants = %d\n", lem->ants);
	lengths = get_set_lengths(set, 3, lem->p_head);
	min = get_efficiency(lengths, 3, lem);
	printf("min = %d\n", min);
*/
 	// min = get_efficiency_2(set, lem->ants, lem->p_head);
	// printf("min 2 = %d\n", min);
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
