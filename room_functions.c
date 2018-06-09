/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:18:58 by dpozinen          #+#    #+#             */
/*   Updated: 2018/06/01 16:18:58 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*get_room_name(t_room *p_head, int index)
{
	while (p_head)
	{
		if (p_head->index == index)
			return (p_head->name);
		p_head = p_head->next;
	}
	return (0);
}

char	*make_room_name(char *line, char c)
{
	char	*room_name;
	int		size;

	size = get_char_index(line, c) + 1;
	MALCHK((room_name = ft_strnew(size)));
	ft_strncpy(room_name, line, size - 1);
	return (room_name);
}

void	print_all_paths(t_path *path, t_room *r_head)
{
	char	*room_name;
	int		i;

	while (path)
	{
		i = 0;
		ft_printf("path name: %2d | path: ", path->name);
		while (i < path->length)
		{
			room_name = get_room_name(r_head, path->path[i]);
			room_name ? ft_printf("%s ", room_name) : 0;
			i++;
		}
		ft_printf("\n");
		path = path->next;
	}
	ft_printf("\n");
}

t_room	*make_room_list(t_main *lem, char *line)
{
	t_room	*t;

	MALCHK((t = (t_room*)malloc(sizeof(t_room))));
	t->index = lem->rooms;
	t->name = line;
	t->next = 0;
	return (t);
}

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
