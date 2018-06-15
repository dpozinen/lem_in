/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:44:12 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/15 14:44:13 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int nargs, char **args)
{
	t_main *lem;

	if (nargs > 2)
		return (0);
	lem = boot_struct();
	read_input(lem);
	if (args[1])
		lem->max_set_n = ft_atoi(args[1]);
	MALCHK(pathfinder(lem));
	choose_paths(lem);
	shutdown(lem, 0, 0);
	system("leaks lem-in");
	return (0);
}
