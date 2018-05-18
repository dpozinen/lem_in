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

# define SHUTLEM(x) if (!x) shutdown(lem, 0);
# define SHUTLEMLINE(x) if (!x) shutdown(lem, line);

typedef struct		s_room
{
	char			*name;
	int				index;
	struct s_room	*next;
}					t_room;

typedef struct		s_main
{
	unsigned int	ants;
	char			*start;
	char			*end;
	int				best_result;
	int				rooms;
	int				**room_matrix;
	t_room			*head;
}					t_main;

void		shutdown(t_main *lem, char *line);//TODO: free int array
t_main		*boot_struct();
void		print_room_list(t_room *head);
t_room		*make_room_list(t_main *lem, char *line);
int			**make_matrix(t_main *lem);
char		*get_room_name(char *line);

int			validate_as_int(char *line);
int			validate_as_room(char *line);
int			validate_as_link(char *line);

int			read_input(t_main *lem);


#endif