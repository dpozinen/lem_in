/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:46:36 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/30 12:46:36 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*init_path(int size)
{
	int *ret;
	int i;

	MALCHK((ret = (int*)malloc(sizeof(int) * size)));
	i = 0;
	while (i < size)
	{
		ret[i] = -1;
		i++;
	}
	return (ret);
}

void	add_point(int i, int *current_path, int size)
{
	int c;

	c = 0;
	while (c < size)
	{
		if (current_path[c] == -1)
		{
			current_path[c] = i;
			return ;
		}
		c++;
	}
}

char	*find_room_name(t_room *p_head, int index)
{
	while (p_head)
	{
		if (p_head->index == index)
			return (p_head->name);
		p_head = p_head->next;
	}
	return (0);
}
