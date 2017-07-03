/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:11:18 by ashulha           #+#    #+#             */
/*   Updated: 2017/02/27 22:11:20 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t d;
	size_t s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = d;
	if (size <= i + 1)
		return (size + s);
	while (i + 1 < size && *src)
		*(dst + i++) = *src++;
	*(dst + i++) = '\0';
	return (d + s);
}
