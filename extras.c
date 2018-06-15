/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:49:43 by dpozinen          #+#    #+#             */
/*   Updated: 2018/06/15 16:49:44 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_all_paths(t_path *path, t_room *r_head)
{
	char	*room_name;
	int		i;

	while (path)
	{
		i = 0;
		ft_printf("path name: %5d | path: ", path->name);
		while (i < path->length + 1)
		{
			room_name = get_room_name(r_head, path->path[i]);
			ft_printf("%s ", room_name);
			i++;
		}
		ft_printf("\n");
		path = path->next;
	}
	ft_printf("\n");
}

void	printf_found(int set_n, t_main *lem)
{
	int		*lengths;
	int		i;

	ft_printf("%d\n", set_n);
	set_n++;
	ft_printf("eff = %d\n", lem->eff);
	ft_printf("ant : ");
	i = -1;
	while (++i < set_n - 1)
		ft_printf("%d ", lem->best_set_ants[i]);
	ft_printf("\n");
	lengths = get_set_lengths(lem->best_set, set_n - 1);
	ft_printf("sum = %d\n", sum_int_array(lengths, set_n - 1));
	free(lengths);
	ft_printf("set : ");
	i = -1;
	while (++i < set_n - 1)
		ft_printf("%d ", (lem->best_set[i])->name);
	ft_printf("\n");
	ft_printf("\n");
}
