/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:11:34 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/15 16:11:34 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_main		*boot_struct(void)
{
	t_main *lem;

	MALCHK((lem = (t_main*)malloc(sizeof(t_main))));
	lem->room_matrix = 0;
	lem->r_head = 0;
	lem->p_head = 0;
	lem->rooms = 0;
	lem->set_n = 3;
	lem->paths = 0;
	lem->best_set = 0;
	lem->istart = -1;
	lem->iend = -1;
	lem->log = 0;
	lem->best_set_ants = make_int_arr(1, 0);
	lem->temp_best_set = 0;
	lem->eff = INT_MAX;
	MALCHK((lem->input_s = ft_strnew(1)));
	return (lem);
}

static void	free_rooms_paths(t_path *path, t_room *room)
{
	t_room	*r;
	t_path	*p;

	while (room)
	{
		r = room->next;
		free(room->name);
		free(room);
		room = r;
	}
	while (path)
	{
		p = path->next;
		free(path->path);
		free(path);
		path = p;
	}
}

void		shutdown(t_main *lem, char *line, int f)
{
	int		i;

	lem->input_s ? free(lem->input_s) : 0;
	lem->best_set ? free(lem->best_set) : 0;
	lem->best_set_ants ? free(lem->best_set_ants) : 0;
	lem->temp_best_set ? free(lem->temp_best_set) : 0;
	free_rooms_paths(lem->p_head, lem->r_head);
	i = -1;
	if (lem->room_matrix)
		while (++i < lem->rooms)
			free(lem->room_matrix[i]);
	lem->room_matrix ? free(lem->room_matrix) : 0;
	free(lem);
	if (line)
		free(line);
	if (f == 1)
	{
		ft_printf("ERROR\n");
		exit(0);
	}
}
