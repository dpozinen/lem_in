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

int		main(void)
{
	t_main *lem;

	MALCHK((lem = boot_struct()));
	read_input(lem);
	find_route(lem);
	shutdown(lem, 0);
	return (0);
}
