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

static void	increment(int *path_congestion, int *lengths)
{
	(*path_congestion)++;
	(*lengths)++;
}

int			get_efficiency(int *lengths, int n_of_paths, int ants, int *path_congestion)//add path congestion to struct
{
	int				worst;
	int		i;
	int		ants_sum;

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

static void	put_in_order(int *paths, int size, int i, int n_of_paths)
{
	if (i - 1 >= 0)
		paths[i - 1]++;
	while (i < size)
	{
		if (paths[i - 1] + 1 <= n_of_paths && paths[i - 1] + 1 != paths[i + 1])
			paths[i] = paths[i - 1] + 1;
		i++;
	}
}

int			save_best_set(int *paths, int set_n, t_main *lem, int *cur_best_sum)//TODO: COUNT BY SUM NOT EFF
{
	int		eff;
	int		*path_congestion;
	int		*lengths;

	eff = 0;
	(void)cur_best_sum;
	MALCHK((lengths = get_set_lengths(paths, set_n, lem->p_head)))
	SHUTLEM((path_congestion = make_int_arr(set_n, 1)));
	MALCHK((eff = get_efficiency(lengths, set_n, lem->ants, path_congestion)));
	if (lem->eff >= eff)
	{
		lem->eff = eff;
		free(lem->best_set);
		free(lem->best_set_ants);
		lem->best_set = intdup(paths, set_n);
		lem->best_set_ants = intdup(path_congestion, set_n);
		free(lengths);
		free(path_congestion);
		return (1);
	}
	free(lengths);
	free(path_congestion);
	return (0);
}

int			traverse_all_paths(int set_n, t_main *lem, int *paths)
{
	int i;
	int f;
	int	cur_best_sum;

	cur_best_sum = INT_MAX;
	f = 0;
	while (sum_int_array(paths, set_n) != (lem->paths - 1) * set_n)
	{
		// if (!set_intersect(paths, lem))
			f += save_best_set(paths, set_n, lem, &cur_best_sum);
		i = 0;
		while (i < set_n)
		{
			if (paths[i] == (lem->paths - 1))
			{
				put_in_order(paths, set_n, i, lem->paths - 1);
				break ;
			}
			else if (i == set_n - 1 && paths[i] < lem->paths - 1)
				paths[i]++;
			i++;
		}
	}
	return (f);
}

int			choose_paths(t_main *lem)
{
	int		set_n;
	// int		min;
	// int		*lengths;
	// int		*set;

	int *paths;
	set_n = 1;
	paths = make_int_arr(set_n, -1);	
	for (int i = 0; i < set_n; i++)
		paths[i] = i;
	while (traverse_all_paths(set_n, lem, paths))
	{
		printf("%d\n", set_n++);
		printf("eff = %d\n", lem->eff);
		for (int i = 0; i < set_n - 1; i++)
			printf("%d ", lem->best_set_ants[i]);
		printf("\n");

		for (int i = 0; i < set_n - 1; i++)
			printf("%d ", lem->best_set[i]);
		printf("\n");
		free(paths);
		paths = make_int_arr(set_n, -1);
		for (int i = 0; i < set_n; i++)
			paths[i] = i;
		printf("\n");
	}
	// printf("fuckup1\n");
	// traverse_all_paths(set_n, lem, paths);
	// printf("INDEX: %d; %d; %d\n", lem->best_set[0], lem->best_set[1], lem->best_set[2]);
	t_path *path;
	path = lem->p_head;
	char *room_name;
	while (path)
	{
		if (path->name == lem->best_set[0] || path->name == lem->best_set[1] || path->name == lem->best_set[2])
 		{	
			for (int i = 0; i < lem->rooms; i++)
			{
				room_name = get_room_name(lem->r_head, path->path[i]);
				room_name ? printf("%s ", room_name) : 0;
			}
			printf("\n");
		}
		path = path->next;
	}
	free(paths);
	return (0);
}
