/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:18:51 by sebbar            #+#    #+#             */
/*   Updated: 2024/10/12 21:31:58 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_root *root, int x, int y)
{
	if (root->game->map[y - 1][x] == 0 || root->game->map[y - 1][x] == 4
		|| (root->game->map[y - 1][x] == 3
			&& root->game->count_coll == root->game->player_coll))
	{
		root->game->map[y][x] = 0;
		root->game->player.y -= 1;
	}
}

void	move_down(t_root *root, int x, int y)
{
	if (root->game->map[y + 1][x] == 0 || root->game->map[y + 1][x] == 4
		|| (root->game->map[y + 1][x] == 3
			&& root->game->count_coll == root->game->player_coll))
	{
		root->game->map[y][x] = 0;
		root->game->player.y += 1;
	}
}

void	move_left(t_root *root, int x, int y)
{
	if (root->game->map[y][x - 1] == 0 || root->game->map[y][x - 1] == 4
		|| (root->game->map[y][x - 1] == 3
			&& root->game->count_coll == root->game->player_coll))
	{
		root->game->map[y][x] = 0;
		root->game->player.x -= 1;
	}
}

void	move_right(t_root *root, int x, int y)
{
	if (root->game->map[y][x + 1] == 0 || root->game->map[y][x + 1] == 4
		|| (root->game->map[y][x + 1] == 3
			&& root->game->count_coll == root->game->player_coll))
	{
		root->game->map[y][x] = 0;
		root->game->player.x += 1;
	}
}
