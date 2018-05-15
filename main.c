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

int		main(int argc, char **args)
{
	t_main *lem;

	if (argc <= 1 || !args || !*args)
		return (0);
	MALCHK((lem = (t_main*)malloc(sizeof(t_main))));
	read_input(lem);
}