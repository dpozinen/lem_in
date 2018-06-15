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

# define SHUTLEM(x) if (!x) shutdown(lem, 0, 1);
# define SHUTLEMLINE(x) if (!x) shutdown(lem, line, 1);

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
	int				max_set_n;
	int				paths;
	int				ants;
	char			*input_s;
	int				istart;
	int				iend;
	int				eff;
	t_path			**temp_best_set;
	t_path			**best_set;
	int				*best_set_ants;
	int				rooms;
	int				**room_matrix;
	t_room			*r_head;
	t_path			*p_head;
}					t_main;

/*
* tools_1.c ▽
*/
int					**make_matrix(t_main *lem);

/*
* validation_functions.c ▽
*/
int		validate_as_int(char *line);
int		validate_as_room(char *line);
int		validate_as_link(char *line, t_main *lem);

/*
* room_functions.c ▽
*/
char	*get_room_name(t_room *p_head, int index);
char	*make_room_name(char *line, char c);
void	print_all_paths(t_path *path, t_room *r_head);
int		get_room_index(t_room *r_head, char *line);
t_room	*make_room_list(t_main *lem, char *line);

/*
* read.c ▽
*/
int			read_input(t_main *lem);

/*
* path_functions.c ▽
*/
int		count_path_length(int *arr, int size);
int		*get_set_lengths(t_path **path_arr, int n_of_paths);
t_path	*get_path(t_path *path, int name);
t_path	**get_paths_pointers(int *paths, int set_n, t_path *p_head);
t_path	**pathdup(t_path **path_arr, int size);

/*
* int_array_functions.c ▽
*/
int		*make_int_arr(int size, int num);
int		find_int_in_arr(int i, int *arr, int size);
int		intersect(int *arr1, int *arr2, int size1, int size2);
int		max_int_arr(int *arr, int size);
int		sum_int_array(int *array, int size);
int		find_min_index(int *arr, int size);
int		*intdup(int *arr, int size);

/*
* find_path.c ▽
*/
int			pathfinder(t_main *lem);
void		add_point(int i, int *current_path, int size);

/*
* choose_path.c ▽
*/
int			choose_paths(t_main *lem);

int			traverse_all_paths(int set_n, t_main *lem, int *paths);
int			save_best_set(t_path **path_arr, int set_n, t_main *lem);

/*
* boot_n_shut.c ▽
*/
void	shutdown(t_main *lem, char *line, int f);
t_main	*boot_struct(void);

/*
* intersect.c ▽
*/
int		set_intersect(t_path **path_arr, int set_n, t_main *lem);
int		get_efficiency(int *lengths, int n_of_paths, int ants, int *path_congestion);

/*
* extras.c ▽
*/
void	printf_found(int set_n, t_main *lem);
void	print_all_paths(t_path *path, t_room *r_head);


#endif