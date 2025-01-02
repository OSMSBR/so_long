/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:18:51 by sebbar            #+#    #+#             */
/*   Updated: 2024/10/12 21:31:50 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_width(t_root *root, char *file)
{
	root->game->width = 0;
	while (file[root->game->width] && file[root->game->width] != '\n')
		root->game->width++;
	if (root->game->width == 0 || file[root->game->width] == 0)
	{
		free(file);
		root_destroy(root, "Map is invalid!", 0);
	}
}
