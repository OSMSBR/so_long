/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:18:51 by sebbar            #+#    #+#             */
/*   Updated: 2024/10/14 04:48:57 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(int **holder, t_coord position, t_root *root)
{
	if (holder[position.y][position.x] == 9
		|| holder[position.y][position.x] == 1
		|| holder[position.y][position.x] == 3
		|| (root->game->coins) == root->game->count_coll)
		return ;
	if (holder[position.y][position.x] == 4)
		root->game->coins += 1;
	holder[position.y][position.x] = 9;
	if (root->game->coins == root->game->count_coll)
		return ;
	fill(holder, (t_coord){position.x + 1, position.y}, root);
	fill(holder, (t_coord){position.x - 1, position.y}, root);
	fill(holder, (t_coord){position.x, position.y + 1}, root);
	fill(holder, (t_coord){position.x, position.y - 1}, root);
}

void	fill_2(int **holder, t_coord position, t_root *root)
{
	if ((root->game->e) == 1 || holder[position.y][position.x] == 1
		|| holder[position.y][position.x] == 8)
		return ;
	if (holder[position.y][position.x] == 3)
		root->game->e += 1;
	holder[position.y][position.x] = 8;
	if (root->game->e == 1)
		return ;
	fill_2(holder, (t_coord){position.x + 1, position.y}, root);
	fill_2(holder, (t_coord){position.x - 1, position.y}, root);
	fill_2(holder, (t_coord){position.x, position.y + 1}, root);
	fill_2(holder, (t_coord){position.x, position.y - 1}, root);
}

void	flood_fill(int **holder, t_coord position, t_root *root)
{
	fill(holder, position, root);
	if (root->game->coins == root->game->count_coll)
	{
		fill_2(holder, position, root);
	}
}

void	flood_check2(int **holder, t_root *root)
{
	root->game->coins = 0;
	root->game->e = 0;
	flood_fill(holder, root->game->player, root);
	if (root->game->coins != root->game->count_coll || root->game->e != 1)
	{
		write(2, "Error\ninvalid path!\n", ft_strlen("Error\ninvalid path!\n"));
		exit(1);
	}
}

void	map_read(t_root *root, char *file, t_game *game)
{
	map_width(root, file);
	map_height(root, file);
	map_isvalid(root, file, game);
	root->game->coll = (t_coord *)malloc(sizeof(t_coord)
			* root->game->count_coll);
	if (root->game->coll == 0)
	{
		free(file);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	if (root->game->map == 0)
	{
		free(file);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	map_parsing(root, file);
	flood_check2(root->game->ndmap, root);
	ndmap_destroy(root->game);
}
