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

void	add_rooms(t_main *lem, char *line)
{
	printf("%s\n", line);
}

void	read_input(t_main *lem)
{
	char	*line;

	RDCHK((get_next_line(0, &line)));
	MALCHK((validate_int_input(line)));
	lem->ants = ft_atoi(line);
	free(line);
	while (get_next_line(0, &line))
	{
		if (validate_as_rooms(line))
			add_rooms(lem, line);
		free(line);
	}
}