/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:47:46 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/29 15:47:46 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_room_index(t_room *r_head, char *line)
{
	while (r_head)
	{
		if (!ft_strcmp(line, r_head->name))
			return (r_head->index);
		r_head = r_head->next;
	}
	return (-1);
}

void	remove_point(int i, int *current_path, int size)
{
	int c;

	c = 0;
	while (c < size)
	{
		if (current_path[c] == i)
		{
			current_path[c] = -1;
			return ;
		}
		c++;
	}
}

int		*intdup(int *arr, int size)
{
	int *ret;
	int i;

	i = 0;
	MALCHK((ret = (int*)malloc(sizeof(int) * size)));
	while (i < size)
	{
		ret[i] = arr[i];
		i++;
	}
	return (ret);
}

int		count_path_length(int *arr, int size)
{
	int c;
	int i;

	i = 0;
	c = 0;
	while (i < size)
	{
		if (arr[i] != -1)
			c++;
		i++;
	}
	return (c);
}

int		find_int_in_arr(int i, int *arr, int size)
{
	int c;

	c = 0;
	while (c < size)
	{
		if (arr[c] == i)
			return (1);
		c++;
	}
	return (0);
}