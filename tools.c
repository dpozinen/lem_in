/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:11:34 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/15 16:11:34 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		validate_as_int(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line))
		{
			free(line);
			return (0);
		}
		line++;
	}
	return (1);
}

int		validate_as_rooms(char *line)
{
	int i;

	if (!ft_isdigit(*line))
		return (0);
	i = 0;
	while (i < 3)
	{
		while (ft_isdigit(*line))
			line++;
		if (*line && *line != ' ')
			return (0);
		line++;
		i++;
	}
	return (1);
}

int		validate_as_links(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line))
		{
			free(line);
			return (0);
		}
		line++;
	}
	return (1);
}