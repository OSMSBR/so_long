/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:29:41 by osebbar           #+#    #+#             */
/*   Updated: 2023/12/29 11:40:07 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (fd < 0)
		return ;
	if (nb < 0)
	{
		nb = nb * (-1);
		if (!write(fd, "-", 1))
			return ;
	}
	if (nb < 10)
	{
		c = nb + 48;
		if (!write(fd, &c, 1))
			return ;
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		c = (nb % 10) + 48;
		if (!write(fd, &c, 1))
			return ;
	}
}
