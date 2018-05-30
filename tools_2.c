/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:58:14 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/17 13:58:14 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*get_room_name(char *line, char c)
{
	char	*room_name;
	int		size;

	size = get_char_index(line, c) + 1;
	MALCHK((room_name = ft_strnew(size)));
	ft_strncpy(room_name, line, size - 1);
	return (room_name);
}

void	print_room_list(t_room *r_head)
{
	while (r_head)
	{
		fprintf(stderr, "name = {%s}; ind = %d\n\n", r_head->name, r_head->index);
		r_head = r_head->next;
	}
}

t_room	*make_room_list(t_main *lem, char *line)
{
	t_room	*t;

	MALCHK((t = (t_room*)malloc(sizeof(t_room))));
	t->index = lem->rooms;
	t->name = ft_strdup(line);
	t->next = 0;
	return (t);
}

char	*ft_strchut(char *line, char c)
{
	char	*ret;
	int		i;
	int		size;

	size = get_char_index(line, c);
	if(!(ret = ft_strnew(size + 1)))
		return (0);
	i = 0;
	while (i < size)
	{
		ret[i] = line[i];
		i++;
	}
	return (ret);
}

int		**make_matrix(t_main *lem)
{
	int	**matrix;
	int i;
	int	j;

	MALCHK((matrix = (int**)malloc(sizeof(int*) * lem->rooms)));
	i = 0;
	while (i < lem->rooms)
	{
		MALCHK((matrix[i] = (int*)malloc(sizeof(int) * lem->rooms)));
		j = 0;
		while (j < lem->rooms)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}