/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 21:21:50 by ashulha           #+#    #+#             */
/*   Updated: 2017/07/02 01:59:40 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	validate_link(t_map *m, char *link)
{
	char **l;

	l = ft_strsplit(link, '-');
	if (l[2] != NULL)
		free_array(l, m, 1);
	free_array(l, m, 0);
}

void		create_tab(t_map *m)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(m->links, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		validate_link(m, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r_1 = room_index(m, l[0], 1)) >= m->q_rooms ||
			(r_2 = room_index(m, l[1], 1)) >= m->q_rooms)
		{
			free_array(l, m, 0);
			free_array(links, m, 1);
		}
		(r_2) ? (m->tab[r_1][r_2] = 1) : 0;
		(r_1) ? (m->tab[r_2][r_1] = 1) : 0;
		free_array(l, m, 0);
	}
	free_array(links, m, 0);
}
