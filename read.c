/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:53:56 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/15 14:53:57 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_link(t_main *lem, char* line)
{
	(void)lem;
	fprintf(stderr, "read link: %s\n", line);
}

void	add_room(t_main *lem, char *line)
{
	(void)lem;
	fprintf(stderr, "made room: %s\n", get_room_name(line));	
}

void	add_command(char *line, t_main *lem, int flag)
{
	get_next_line(0, &line);
	if (!validate_as_room(line))
		shutdown(lem, line);
	add_room(lem, line);
	if (flag == 1)
		lem->start = ft_strdup(get_room_name(line));
	else
		lem->end = ft_strdup(get_room_name(line));		
}

int		check_command(char *line, t_main *lem)
{
	if (!*line)
		return (0);
	if (!ft_strcmp("##start", line))
		add_command(line, lem, 1);
	else if (!ft_strcmp("##end", line))
		add_command(line, lem, 2);
	return (1);
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
			check_command(line, lem);
		else if (validate_as_room(line))
			add_room(lem, line);
		else if (validate_as_link(line))
			add_link(lem, line);
		free(line);
	}
	return (1);
}