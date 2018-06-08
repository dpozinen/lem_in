/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:11:00 by dpozinen          #+#    #+#             */
/*   Updated: 2018/06/01 16:11:00 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_min_path(t_path *path)
{
	int min;

	min = path->length;
	while (path)
	{
		if (min > path->length)
			min = path->length;
		path = path->next;
	}
	return (min);
}

int		get_path_length(t_path *path, int name)
{
	while (path)
	{
		if (name == path->name)
			return (path->length);
		path = path->next;
	}
	return (0);
}

int		check_other_paths(int *arr, int worst, int size, int n_of_paths)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] >= worst)
			c++;
		if ((c >= 2 && n_of_paths >= 2) || (c == 1 && n_of_paths == 1))
			return (1);
		i++;
	}
	return (0);
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
	return (c - 1);
}

int		*get_set_lengths(int *set, int n_of_paths, t_path *path)
{
	int	*lengths;
	int	i;

	MALCHK((lengths = make_int_arr(n_of_paths, 0)));
	i = 0;
	while (i < n_of_paths)
	{
		lengths[i] = get_path_length(path, set[i]);
		i++;
	}
	return (lengths);
}
