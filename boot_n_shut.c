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

t_main	*boot_struct(void)//TODO: null where necessary
{
	t_main *lem;

	MALCHK((lem = (t_main*)malloc(sizeof(t_main))));
	lem->start = 0;
	lem->end = 0;
	lem->room_matrix = 0;
	lem->r_head = 0;
	lem->p_head = 0;
	lem->rooms = 0;
	lem->paths = 0;
	MALCHK((lem->input_s = ft_strnew(1)));
	return (lem);
}

void	shutdown(t_main *lem, char *line)//TODO: all
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
