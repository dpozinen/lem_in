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

int		add_path_to_list(int *current_path, t_main *lem)
{
	t_path	*path;

	MALCHK((path = (t_path*)malloc(sizeof(t_path))));
	path->path = intdup(current_path, lem->rooms);
	path->name = (lem->p_head ? lem->p_head->name + 1 : 0);
	path->length = count_path_length(current_path, lem->rooms);
	if (!lem->p_head)
	{
		lem->p_head = path;
		return (1);
	}
	path->next = lem->p_head;
	lem->p_head = path;
	return (1);
}

void	find_paths(int cur, int *current_path, t_main *lem)
{
	int i;
	char *room_name;

	if (cur == lem->iend)
	{
		add_path_to_list(current_path, lem);
		for (int i = 0; i < lem->rooms; i++)
		{
			room_name = find_room_name(lem->r_head, current_path[i]);
			room_name ? printf("%s ", room_name) : 0;
		}
		printf("\n");
		return ;
	}
	i = 0;
	while (i < lem->rooms)
	{
		if (lem->room_matrix[cur][i] == 1 && !find_int_in_arr(i, current_path, lem->rooms))
		{
			add_point(i, current_path, lem->rooms);
			find_paths(i, current_path, lem);
			remove_point(i, current_path, lem->rooms);
		}
		i++;
	}
}

int		execute(t_main *lem)
{
	int		*current_path;

	MALCHK((current_path = init_path(lem->rooms)));
	current_path[0] = lem->istart;
	find_paths(lem->istart, current_path, lem);
	choose_paths(lem);
	printf("found\n");
	return (0);
}