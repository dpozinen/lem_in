/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:34:23 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/18 11:34:26 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	add_link(t_main *lem, char *line)
{
	int		i;
	int		j;
	char	*room_name;

	if (!lem->room_matrix)
		SHUTLEMLINE((lem->room_matrix = make_matrix(lem)));
	room_name = make_room_name(line, '-');
	i = get_room_index(lem->r_head, room_name);
	free(room_name);
	j = get_room_index(lem->r_head, (line + get_char_index(line, '-') + 1));
	lem->room_matrix[i][j] = 1;
	lem->room_matrix[j][i] = 1;
}

static void	add_room(t_main *lem, char *line)
{
	t_room	*t;
	char	*room_name;

	SHUTLEMLINE((room_name = make_room_name(line, ' ')));
	if (!lem->r_head)
	{
		SHUTLEMLINE((lem->r_head = make_room_list(lem, room_name)));
		lem->rooms++;
		return ;
	}
	t = lem->r_head;
	SHUTLEMLINE(ft_strcmp(t->name, room_name));
	while (t->next)
	{
		SHUTLEMLINE(ft_strcmp(t->name, room_name));
		t = t->next;
	}
	SHUTLEMLINE((t->next = make_room_list(lem, room_name)));
	lem->rooms++;
}

static void	add_command(char *line, t_main *lem)
{
	int		f;

	f = 0;
	if (!ft_strcmp("##start", line))
		f = 1;
	else if (!ft_strcmp("##end", line))
		f = 2;
	if (f == 0)
		return ;
	get_next_line(0, &line);
	SHUTLEMLINE(validate_as_room(line));
	if (f == 1)
		lem->istart = lem->rooms;
	else
		lem->iend = lem->rooms;
	add_room(lem, line);
	free(line);
}

int			read_input(t_main *lem)
{
	char	*line;

	RDCHK(get_next_line(0, &line));
	SHUTLEMLINE(validate_as_int(line));
	MALCHK((lem->ants = ft_atoi(line)));
	free(line);
	while (get_next_line(0, &line))
	{
		// MALCHK((lem->input_s = free_n_join(lem->input_s, line, 1)));
		if (*line == '#')
			add_command(line, lem);
		else if (validate_as_room(line))
			add_room(lem, line);
		else if (validate_as_link(line, lem))
			add_link(lem, line);
		else
		 	break ; //shutdown(lem, line);
		free(line);
	}
	return (1);
}
