/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 21:42:11 by ashulha           #+#    #+#             */
/*   Updated: 2017/07/02 02:13:31 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_map
{
	char		**rooms;
	char		*rooms_list;
	char		*ants_str;
	char		*links;
	int			q_rooms;
	int			ants;
	int			started;
	int			curr_room;
	int			p_ind;
	int			*path;
	int			**tab;
	int			good[2];
	int			new_line;
	int			init_2;
}				t_map;

void			count_ants(t_map *m, char *line);
void			rooms(t_map *m, char *line);
void			links(t_map *m, char *line);

void			add_rooms(t_map *m);
void			create_tab(t_map *m);
int				solution(t_map *m, int i);

char			*join_str(char *s1, char *s2, int clean);
void			free_array(char **array, t_map *m, int error);
int				room_index(t_map *m, char *room_name, int start);

void			result(t_map *m);
void			print_matrix(t_map *m);
void			exit_func(t_map *m, int error);

#endif
