/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:52:03 by dpozinen          #+#    #+#             */
/*   Updated: 2018/06/18 15:52:03 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	move_each(int length, int *path_arr, int *path_ants, int *last)
{
	int i;

	i = length;
	while (i > 0)
	{
		path_arr[i] = path_arr[i - 1];
		i--;
	}
	path_arr[i] = 0;
	if (!*path_ants)
		return ;
	(*last)++;
	path_arr[i] = *last;
	(*path_ants)--;
}

void		move_ants(t_main *lem, t_path **set, int **set_arr, int *last)
{
	int i;

	i = 0;
	while (i < lem->set_n)
	{
		move_each(set[i]->length, set_arr[i], &(lem->best_set_ants[i]), last);
		i++;
	}
}

void		print_move(int **set_arr, char ***set_r, int set_n, t_path **set)
{
	int i;
	int j;

	i = 0;
	while (i < set_n)
	{
		j = set[i]->length;
		while (j > 0)
		{
			if (set_arr[i][j] != 0)
				ft_printf("L%d-%s ", set_arr[i][j], set_r[i][j]);
			j--;
		}
		i++;
	}
}

static void	free_arr_rooms(int **set_arr, int set_n, char ***set_rooms)
{
	int i;

	i = 0;
	while (i < set_n)
	{
		free(set_arr[i]);
		free(set_rooms[i]);
		i++;
	}
	free(set_arr);
	free(set_rooms);
}

int			output(t_path **set, t_main *lem)
{
	int		**set_arr;
	char	***set_rooms;
	int		set_n;
	int		last;

	MALCHK((set_arr = make_set_arr(set, &set_n)));
	MALCHK((set_rooms = make_set_rooms(set, set_n, lem->r_head)));
	lem->set_n = set_n;
	last = 0;
	(*set)->length == 1 ? ft_printf("\n") : 0;
	while (last <= lem->ants)
	{
		move_ants(lem, set, set_arr, &last);
		print_move(set_arr, set_rooms, set_n, set);
		if (last == lem->ants && is_last_end(set_arr, set, set_n))
			break ;
		(*set)->length > 1 ? ft_printf("\n") : 0;
	}
	(*set)->length == 1 ? ft_printf("\n") : 0;
	free_arr_rooms(set_arr, set_n, set_rooms);
	return (1);
}
