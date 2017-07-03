/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:52:19 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/10 11:10:08 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_nmin(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*ft_buildstr(char *str, int i, int n)
{
	int		k;

	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		str[i] = '\0';
		if (n < 0)
			n = n * -1;
		while (n > 0)
		{
			i--;
			k = n % 10;
			str[i] = k + '0';
			n = n / 10;
		}
		if (i != 0)
			str[0] = '-';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;

	if (n == -2147483648)
	{
		str = (char*)malloc(12);
		return (ft_nmin(str));
	}
	i = ft_count_digits(n);
	str = (char*)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	return (ft_buildstr(str, i, n));
}
