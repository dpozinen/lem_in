/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:14:31 by dpozinen          #+#    #+#             */
/*   Updated: 2018/06/01 16:14:31 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (!*line)
		return (0);
	if (get_room_index(lem->r_head, make_room_name(line, '-')) == -1)
		return (0);
	while (*line && *line != '-')
		line++;
	line++;
	if (get_room_index(lem->r_head, line) == -1)
		return (0);
	return (1);
}
