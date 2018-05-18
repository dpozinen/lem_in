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

void	add_link(t_main *lem, char *line)
{
	int i;
	int j;

	if (!lem->room_matrix)
		SHUTLEMLINE((lem->room_matrix = make_matrix(lem)));
	i = ft_atoi(line);
	j = ft_atoi((line + get_char_index(line, '-') + 1));
	lem->room_matrix[i][j] = 1;
}

void	add_room(t_main *lem, char *line)
{
	t_room	*t;
	char	*room_name;

	SHUTLEMLINE((room_name = get_room_name(line)));
	if (!lem->head)
	{
		SHUTLEMLINE((lem->head = make_room_list(lem, room_name)));
		lem->rooms++;
		return ;
	}
	t = lem->head;
	SHUTLEMLINE(ft_strcmp(t->name, room_name));
	while (t->next)
	{
		SHUTLEMLINE(ft_strcmp(t->name, room_name));
		t = t->next;
	}
	SHUTLEMLINE((t->next = make_room_list(lem, room_name)));
	lem->rooms++;
}

void	add_command(char *line, t_main *lem)
{
	int f;

	f = 0;
	if (!ft_strcmp("##start", line))
		f = 1;
	else if (!ft_strcmp("##end", line))
		f = 2;
	if (f == 0)
		return ;
	get_next_line(0, &line);
	SHUTLEMLINE(validate_as_room(line));
	add_room(lem, line);
	if (f == 1)
		lem->start = ft_strdup(get_room_name(line));
	else
		lem->end = ft_strdup(get_room_name(line));
}

int		read_input(t_main *lem)
{
	char	*line;

	RDCHK(get_next_line(0, &line));
	MALCHK(validate_as_int(line));
	MALCHK((lem->ants = ft_atoi(line)));
	free(line);
	while (get_next_line(0, &line))
	{
		if (*line == '#')
			add_command(line, lem);
		else if (validate_as_room(line))
			add_room(lem, line);
		else if (validate_as_link(line))
			add_link(lem, line);
		else
			break ;//shutdown(lem, line);
		free(line);
	}
	print_room_list(lem->head);
	fprintf(stderr, "start = %s, end = %s\n", lem->start, lem->end);
	for (int i = 0; i < lem->rooms; i++)
	{	
		for (int j = 0; j < lem->rooms; j++)
			printf("%d ", lem->room_matrix[i][j]);
		printf("\n");
	}
	return (1);
}
