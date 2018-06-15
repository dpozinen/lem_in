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

int			choose_paths(t_main *lem)
{
	int		set_n;
	int		*paths;
	int		i;

	set_n = 1;
	MALCHK((paths = make_int_arr(set_n, -1)));
	i = -1;
	while (++i < set_n)
		paths[i] = i;
	print_all_paths(lem->p_head, lem->r_head); // DEL
	while (set_n <= lem->max_set_n && traverse_all_paths(set_n, lem, paths))
	{
		set_n++;
		free(paths);
		if (!save_best_set(lem->temp_best_set, set_n - 1, lem))
			return (0);
		free(lem->temp_best_set);
		lem->temp_best_set = 0;
		printf_found(set_n - 1, lem); // DEL
		MALCHK((paths = make_int_arr(set_n, -1)));
		i = -1;
		while (++i < set_n)
			paths[i] = i;
	}
	free(paths);
	return (1);
}
