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
	lem->room_matrix = 0;
	lem->r_head = 0;
	lem->p_head = 0;
	lem->rooms = 0;
	lem->paths = 0;
	lem->best_set = make_int_arr(1, 0);
	lem->best_set_ants = make_int_arr(1, 0);
	lem->eff = INT_MAX;
	MALCHK((lem->input_s = ft_strnew(1)));
	return (lem);
}

void	shutdown(t_main *lem, char *line)
{
	t_room	*r;
	t_path	*p;
	int		i;


	free(lem->input_s);
	free(lem->best_set);
	free(lem->best_set_ants);
	while (lem->r_head)
	{
		r = lem->r_head->next;

		free(lem->r_head->name);
		free(lem->r_head);
		lem->r_head = r;
	}
	while (lem->p_head)
	{
		p = lem->p_head->next;
		free(lem->p_head->path);
		free(lem->p_head);
		lem->p_head = p;
	}
	i = 0;
	while (i < lem->rooms)
	{
		free(lem->room_matrix[i]);
		i++;
	}
	free(lem->room_matrix);
	free(lem);
	if (line)
		free(line);
	ft_printf("ERROR\n");
	// exit(0);
}
