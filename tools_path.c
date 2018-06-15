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

t_path	**pathdup(t_path **path_arr, int size)
{
	t_path	**ret;
	int		i;

	MALCHK((ret = (t_path**)malloc(sizeof(t_path*) * (size + 1))));
	ret[size] = 0;
	i = 0;
	while (i < size)
	{
		ret[i] = path_arr[i];
		i++;
	}
	return (ret);
}

t_path	*get_path(t_path *path, int name)
{
	while (path)
	{
		if (name == path->name)
			return (path);
		path = path->next;
	}
	return (0);
}

t_path	**get_paths_pointers(int *paths, int set_n, t_path *p_head)
{
	t_path	**ret;
	int		i;

	MALCHK((ret = (t_path**)malloc(sizeof(t_path*) * (set_n + 1))));
	ret[set_n] = 0;
	i = 0;
	while (i < set_n)
	{
		ret[i] = get_path(p_head, paths[i]);
		i++;
	}
	return (ret);
}

int		count_path_length(int *arr, int size)
{
	int i;

	i = 0;
	while (arr[i] != -1 && i < size)
		i++;
	return (i - 1);
}

int		*get_set_lengths(t_path **path_arr, int set_n)
{
	int	*lengths;
	int	i;

	MALCHK((lengths = make_int_arr(set_n, 0)));
	i = 0;
	while (i < set_n)
	{
		lengths[i] = (path_arr[i])->length;
		i++;
	}
	return (lengths);
}
