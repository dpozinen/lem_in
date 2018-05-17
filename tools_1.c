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

t_main		*boot_struct(void)
{
	t_main *lem;

	MALCHK((lem = (t_main*)malloc(sizeof(t_main))));
	lem->start = 0;
	lem->end = 0;
	lem->rooms_matrix = 0;
	lem->head = 0;
	return (lem);
}

void	shutdown(t_main *lem, char *line)//TODO: free int array & room list
{
	if (lem)
	{
		if (lem->start)
			free(lem->start);
		if (lem->end)
			free(lem->end);
	}
	free(lem);
	if (line)
		free(line);
	exit(0);
}

int		validate_as_int(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line))
			return (0);
		line++;
	}
	return (1);
}

int		validate_as_room(char *line)
{
	int i;
	int	spaces;

	if (!*line || !ft_isdigit(*line))
		return (0);
	i = 0;
	spaces = 0;
	while (i < 3)
	{
		while (ft_isdigit(*line))
			line++;
		if (*line && *line != ' ')
			return (0);
		*line == ' ' ? spaces++ : 0;
		line++;
		i++;
	}
	if (*line != '\0' || spaces != 2)
		return (0);
	return (1);
}

int		validate_as_link(char *line)
{
	if (!*line || !ft_isdigit(*line))
		return (0);
	while (*line && ft_isdigit(*line))
		line++;
	if ((*line && *line != '-') || !*line)
		return (0);
	if (!validate_as_int(++line))
		return (0);
	return (1);
}