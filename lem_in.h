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

typedef struct		s_path
{
	int				*path;
	int				name;
	int				length;
	struct s_path	*next;
}					t_path;

typedef struct		s_room
{
	char			*name;
	int				index;
	struct s_room	*next;
}					t_room;

typedef struct		s_main
{
	int				paths;
	unsigned int	ants;
	char			*input_s;
	char			*start;
	int				istart;
	char			*end;
	int				iend;
	int				best_result;
	int				rooms;
	int				**room_matrix;
	t_room			*r_head;
	t_path			*p_head;
}					t_main;

void		shutdown(t_main *lem, char *line);//TODO: free int array
t_main		*boot_struct();
void		print_room_list(t_room *r_head);
t_room		*make_room_list(t_main *lem, char *line);
int			**make_matrix(t_main *lem);
char		*get_room_name(char *line, char c);
int			get_room_index(t_room *r_head, char *line);
int			*init_path(int size);
void		remove_point(int i, int *current_path, int size);
int			*intdup(int *arr, int size);
int			count_path_length(int *arr, int size);
int			find_int_in_arr(int i, int *arr, int size);
void		add_point(int i, int *current_path, int size);
char		*find_room_name(t_room *p_head, int index);

int			validate_as_int(char *line);
int			validate_as_room(char *line);
int			validate_as_link(char *line, t_main *lem);

int			read_input(t_main *lem);
int			execute(t_main *lem);
int			choose_paths(t_main *lem);
#endif