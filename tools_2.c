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