/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:42:59 by dpozinen          #+#    #+#             */
/*   Updated: 2018/06/18 16:42:59 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			**make_set_arr(t_path **set, int *set_n)
{
	int	**ret;
	int	i;

	*set_n = 0;
	while (set[*set_n])
		(*set_n)++;
	MALCHK((ret = (int**)malloc(sizeof(int*) * (*set_n))));
	i = 0;
	while (i < *set_n)
	{
		MALCHK((ret[i] = make_int_arr(set[i]->length + 1, 0)));
		i++;
	}
	return (ret);
}

static char	**make_path_rooms(int *path, int length, t_room *r_head)
{
	char	**ret;
	int		i;

	MALCHK((ret = (char**)malloc(sizeof(char*) * (length + 1))));
	ret[length] = 0;
	i = 0;
	while (i < length)
	{
		ret[i] = get_room_name(r_head, path[i]);
		i++;
	}
	return (ret);
}

char		***make_set_rooms(t_path **set, int set_n, t_room *r_head)
{
	char	***ret;
	int		i;

	i = 0;
	MALCHK((ret = (char***)malloc(sizeof(char**) * (set_n + 1))));
	ret[set_n] = 0;
	while (i < set_n)
	{
		ret[i] = make_path_rooms(set[i]->path, set[i]->length + 1, r_head);
		i++;
	}
	return (ret);
}

int			is_last_end(int **set_arr, t_path **set, int set_n)
{
	int i;
	int j;

	i = 0;
	while (i < set_n)
	{
		j = 0;
		while (j < set[i]->length + 1)
		{
			if (set_arr[i][j] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
