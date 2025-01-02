/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:48:55 by osebbar           #+#    #+#             */
/*   Updated: 2023/12/31 20:51:45 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int a, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)a;
		i++;
	}
	return (ptr);
}
