/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_choose_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:24:39 by dpozinen          #+#    #+#             */
/*   Updated: 2018/06/15 17:24:39 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	put_in_order(int *paths, int size, int i, int n_of_paths)
{
	if (i - 1 >= 0)
		paths[i - 1]++;
	while (i < size)
	{
		if (paths[i - 1] + 1 <= n_of_paths && paths[i - 1] + 1 != paths[i + 1])
			paths[i] = paths[i - 1] + 1;
		i++;
	}
	return (1);
}

static int	save_best_sum(t_path **p, int set_n, t_main *lem, int *best_sum)
{
	int		*lengths;
	int		t_sum;

	MALCHK((lengths = get_set_lengths(p, set_n)));
	t_sum = sum_int_array(lengths, set_n);
	t_sum > *best_sum ? free(lengths) : 0;
	if (t_sum > *best_sum)
		return (0);
	*best_sum = t_sum;
	if (lem->temp_best_set)
		free(lem->temp_best_set);
	free(lengths);
	MALCHK((lem->temp_best_set = pathdup(p, set_n)));
	return (1);
}

static int	traverse_end(int set_n, int paths)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (i < set_n)
	{
		sum += paths;
		paths--;
		i++;
	}
	return (sum);
}

int			traverse_all_paths(int set_n, t_main *lem, int *paths)
{
	int		i;
	int		best_sum;
	int		end;
	t_path	**t_path_arr;

	end = traverse_end(set_n, lem->paths - 1);
	best_sum = INT_MAX;
	while (sum_int_array(paths, set_n) <= end)
	{
		t_path_arr = get_paths_pointers(paths, set_n, lem->p_head);
		if (!set_intersect(t_path_arr, set_n, lem))
			save_best_sum(t_path_arr, set_n, lem, &best_sum);
		i = 0;
		while (i < set_n)
		{
			if (paths[i] == (lem->paths - 1) && set_n != 1 &&
				put_in_order(paths, set_n, i, lem->paths - 1))
				break ;
			else if (i == set_n - 1 && paths[i] <= lem->paths - 1)
				paths[i]++;
			i++;
		}
		free(t_path_arr);
	}
	return (1);
}

int			save_best_set(t_path **path_arr, int set_n, t_main *lem)
{
	int		*lengths;
	int		*path_congestion;
	int		eff;

	if (!lem->temp_best_set)
		return (0);
	MALCHK((lengths = get_set_lengths(path_arr, set_n)));
	MALCHK((path_congestion = make_int_arr(set_n, 1)));
	eff = get_efficiency(lengths, set_n, lem->ants, path_congestion);
	if (lem->eff >= eff)
	{
		lem->eff = eff;
		if (lem->best_set)
			free(lem->best_set);
		free(lem->best_set_ants);
		MALCHK((lem->best_set = pathdup(path_arr, set_n)));
		MALCHK((lem->best_set_ants = intdup(path_congestion, set_n)));
	}
	free(lengths);
	free(path_congestion);
	return (lem->eff >= eff);
}
