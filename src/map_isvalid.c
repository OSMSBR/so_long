/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:18:51 by sebbar            #+#    #+#             */
/*   Updated: 2024/10/12 21:31:41 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	isborder(t_root *root, int i)
{
	if (i < root->game->width || i > (root->game->width + 1)
		* (root->game->height - 1) || i % (root->game->width + 1) == 0 || i
		% (root->game->width + 1) == root->game->width - 1)
		return (1);
	return (0);
}

static void	isvalid(t_root *root, char *file, int i, t_game *game)
{
	if (file[i] == 'P')
	{
		root->game->count_player++;
		(void)game;
	}
	else if (file[i] == 'E')
		root->game->count_exit++;
	else if (file[i] == 'C')
		root->game->count_coll++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		root_destroy(root, "Map is invalid!", 0);
	}
}

void	map_isvalid(t_root *root, char *file, t_game *game)
{
	int	i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (isborder(root, i))
		{
			if (file[i] != '1')
			{
				free(file);
				root_destroy(root, "Map needs to be surrounded by walls.", 0);
			}
		}
		else
			isvalid(root, file, i, game);
	}
	if (root->game->count_player != 1 || root->game->count_exit != 1
		|| root->game->count_coll < 1)
	{
		free(file);
		root_destroy(root, "Map is invalid!", 0);
	}
}
