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

int			save_best_set(int *paths, int set_n, t_main *lem, int *best_sum)
{
	int		eff;
	int		*path_congestion;
	int		*lengths;
	int		t_sum;

	eff = 0;
	MALCHK((lengths = get_set_lengths(paths, set_n, lem->p_head)));
	// if (lengths[0] == 1)
	// 	printf("111\n");
	t_sum = sum_int_array(lengths, set_n);
	t_sum > *best_sum ? free(lengths) : 0;
	if (t_sum > *best_sum)
		return (0);
	*best_sum = t_sum;
	SHUTLEM((path_congestion = make_int_arr(set_n, 1)));
	MALCHK((eff = get_efficiency(lengths, set_n, lem->ants, path_congestion)));
	if (lem->eff >= eff)
	{
		lem->eff = eff;
		free(lem->best_set);
		free(lem->best_set_ants);
		lem->best_set = intdup(paths, set_n);
		lem->best_set_ants = intdup(path_congestion, set_n);
	}
	free(lengths);
	free(path_congestion);
	return (lem->eff >= eff);
}

int			traverse_end(int set_n, int paths)
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
	// printf("sum = %d\n", sum);
	return (sum);

}

int			traverse_all_paths(int set_n, t_main *lem, int *paths)
{
	int i;
	int f;
	int	best_sum;

	best_sum = INT_MAX;
	f = 0;
	while (sum_int_array(paths, set_n) <= traverse_end(set_n, lem->paths - 1))
	{
		if (!set_intersect(paths, set_n, lem))
			f += save_best_set(paths, set_n, lem, &best_sum);
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
	}
	return (f);
}

void printf_found(int set_n, t_main *lem)
{
	ft_printf("%d\n", set_n);
	set_n++;
	ft_printf("eff = %d\n", lem->eff);
	ft_printf("ant : ");
	for (int i = 0; i < set_n - 1; i++)
		ft_printf("%d ", lem->best_set_ants[i]);
	ft_printf("\n");
	ft_printf("set : ");
	for (int i = 0; i < set_n - 1; i++)
		ft_printf("%d ", lem->best_set[i]);
	ft_printf("\n");
	ft_printf("\n");
}

int			choose_paths(t_main *lem)
{
	int		set_n;
	int		*paths;
	int		i;

	set_n = 1;
	paths = make_int_arr(set_n, -1);
	i = -1;
	while (++i < set_n)
		paths[i] = i;
	while (traverse_all_paths(set_n, lem, paths) && set_n < lem->paths - 1)
 	{
		// TODO while lengths less than ants
		printf_found(set_n, lem);
		set_n++;
		free(paths);
		paths = make_int_arr(set_n, -1);
		i = -1;
		while (++i < set_n)
			paths[i] = i;
	}
	free(paths);
	return (0);
}
