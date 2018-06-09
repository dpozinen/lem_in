/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:46:42 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/21 11:46:42 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	remove_point(int i, int *current_path, int size)
{
	int c;

	c = 0;
	while (c < size)
	{
		if (current_path[c] == i)
		{
			current_path[c] = -1;
			return ;
		}
		c++;
	}
}

void		add_point(int i, int *current_path, int size)
{
	int c;

	c = 0;
	while (c < size)
	{
		if (current_path[c] == -1)
		{
			current_path[c] = i;
			return ;
		}
		c++;
	}
}

int			add_path_to_list(int *current_path, t_main *lem)
{
	t_path	*path;

	MALCHK((path = (t_path*)malloc(sizeof(t_path))));
	path->path = intdup(current_path, lem->rooms);
	path->name = (lem->p_head ? lem->p_head->name + 1 : 0);
	path->length = count_path_length(current_path, lem->rooms);
	path->next = 0;
	if (!lem->p_head)
	{
		lem->p_head = path;
		lem->p_head->next = 0;
		return (1);
	}
	path->next = lem->p_head;
	lem->p_head = path;
	return (1);
}

static void	find_paths(int cur, int *current_path, t_main *lem)
{
	int i;

	if (cur == lem->iend)
	{
		add_path_to_list(current_path, lem);
		lem->paths++;
		return ;
	}
	i = 0;
	while (i < lem->rooms)
	{
		if (lem->room_matrix[cur][i] == 1 &&
			!find_int_in_arr(i, current_path, lem->rooms))
		{
			add_point(i, current_path, lem->rooms);
			find_paths(i, current_path, lem);
			remove_point(i, current_path, lem->rooms);
		}
		i++;
	}
}

int			pathfinder(t_main *lem)
{
	int		*current_path;

	MALCHK((current_path = make_int_arr(lem->rooms, -1)));
	current_path[0] = lem->istart;
	find_paths(lem->istart, current_path, lem);
	print_all_paths(lem->p_head, lem->r_head);
	free(current_path);
	return (0);
}
