/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:18:38 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/06 19:18:40 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *node;
	t_list *n_alst;

	n_alst = *alst;
	while (n_alst != NULL)
	{
		node = n_alst->next;
		del(n_alst, n_alst->content_size);
		n_alst = node;
	}
	*alst = NULL;
}
