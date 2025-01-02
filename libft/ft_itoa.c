/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:15:53 by osebbar           #+#    #+#             */
/*   Updated: 2023/12/28 17:43:14 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_length(int nb)
{
	unsigned int	count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static size_t	alloc_len(int nb)
{
	size_t	size;

	if (nb <= 0)
		size = nb_length(nb) + 2;
	else
		size = nb_length(nb) + 1;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	long	x;

	x = n;
	size = alloc_len(x);
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	if (x == 0)
		str[0] = '0';
	if (x < 0)
	{
		str[0] = '-';
		x = -x;
	}
	str[size - 1] = '\0';
	while (x)
	{
		--size;
		str[size - 1] = (x % 10) + 48;
		x = x / 10;
	}
	return (str);
}
