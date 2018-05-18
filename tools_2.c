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

char	*get_room_name(char *line)
{
	char	*room_name;
	int		size;

	size = get_char_index(line, ' ') + 1;
	MALCHK((room_name = ft_strnew(size)));
	ft_strncpy(room_name, line, size - 1);
	return (room_name);
}

void	print_room_list(t_room *head)
{
	while (head)
	{
		fprintf(stderr, "name = {%s}; ind = %d\n\n", head->name, head->index);
		head = head->next;
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