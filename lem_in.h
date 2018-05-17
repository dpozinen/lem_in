/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:44:53 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/15 14:44:54 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				index;
}					t_room;

typedef struct		s_main
{
	unsigned int	ants;
	char			*start;
	char			*end;
	int				best_result;
	int				room_quantity;
	int				**rooms_matrix;
	t_room			**head;
}					t_main;

void		shutdown(t_main *lem, char *line);//TODO: free int array & room list
t_main		*boot_struct();

int			validate_as_int(char *line);
int			validate_as_room(char *line);
int			validate_as_link(char *line);

int			read_input(t_main *lem);
char		*get_room_name(char *line);

#endif