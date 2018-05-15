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
	int				**rooms_matrix;
	t_room			**start;
}					t_main;

#endif