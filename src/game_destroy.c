/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:18:51 by sebbar            #+#    #+#             */
/*   Updated: 2024/10/12 23:03:36 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_destroy(t_game *game)
{
	int	i;

	if (game != 0)
	{
		if (game->coll != 0)
			free(game->coll);
		if (game->map != 0)
		{
			i = 0;
			while (i < game->height)
				free(game->map[i++]);
			free(game->map);
		}
		free(game);
	}
}

void	ndmap_destroy(t_game *game)
{
	int	i;

	if (game != 0)
	{
		if (game->ndmap != 0)
		{
			i = 0;
			while (i < game->height)
				free(game->ndmap[i++]);
			free(game->ndmap);
		}
	}
}
