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

t_main	*boot_struct(void)
{
	t_main *lem;

	MALCHK((lem = (t_main*)malloc(sizeof(t_main))));
	lem->start = 0;
	lem->end = 0;
	lem->room_matrix = 0;
	lem->r_head = 0;
	lem->p_head = 0;
	lem->rooms = 0;
	return (lem);
}

void	shutdown(t_main *lem, char *line)//TODO: free int array
{
	t_room *t;

	if (lem)
	{
		if (lem->start)
			free(lem->start);
		if (lem->end)
			free(lem->end);
	}
	while (lem->r_head)
	{
		t = lem->r_head->next;
		free(lem->r_head->name);
		free(lem->r_head);
		lem->r_head = t;
	}
	free(lem);
	if (line)
		free(line);
	ft_printf("ERROR\n");
	exit(0);
}

int		validate_as_int(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line))
			return (0);
		line++;
	}
	return (1);
}

int		validate_as_room(char *line)
{
	int i;
	int	spaces;

	MALCHK(*line);
	MALCHK((*line != 'L'));
	i = get_char_index(line, ' ') + 1;
	spaces = 1;
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			return (0);
		line[i] == ' ' ? spaces++ : 0;
		i++;
	}
	if (spaces != 2)
		return (0);
	return (1);
}

int		validate_as_link(char *line, t_main *lem)
{
	if (get_room_index(lem->r_head, get_room_name(line, '-')) == -1)
		return (0);
	if (!*line || !ft_isdigit(*line))
		return (0);
	while (*line && ft_isdigit(*line))
		line++;
	if ((*line && *line != '-') || !*line)
		return (0);
	line++;
	if (get_room_index(lem->r_head, line) == -1)
		return (0);
	if (!validate_as_int(line))
		return (0);
	return (1);
}

