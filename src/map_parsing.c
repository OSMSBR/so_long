/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:18:51 by sebbar            #+#    #+#             */
/*   Updated: 2024/10/14 03:09:37 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_matrix(t_root *root, char *file, int **m, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	root->game->map = 0;
	free(file);
	root_destroy(root, "map_parsing(): malloc()", errno);
}

static void	get_coord(t_root *root, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		root->game->player.x = k % (root->game->width + 1);
		root->game->player.y = k / (root->game->width + 1);
		file[k] = '2';
	}
	else if (file[k] == 'E')
	{
		root->game->exit.x = k % (root->game->width + 1);
		root->game->exit.y = k / (root->game->width + 1);
		file[k] = '3';
	}
	else if (file[k] == 'C')
	{
		root->game->coll[*obj].x = k % (root->game->width + 1);
		root->game->coll[*obj].y = k / (root->game->width + 1);
		file[k] = '4';
		(*obj)++;
	}
}

void	fill_map(t_root *root)
{
	int	j;
	int	i;

	j = 0;
	root->game->ndmap = (int **)malloc(sizeof(int *) * root->game->height);
	while (j < root->game->height)
	{
		root->game->map[j] = (int *)malloc(sizeof(int) * root->game->width);
		root->game->ndmap[j] = (int *)malloc(sizeof(int) * root->game->width);
		i = 0;
		while (i < root->game->width)
		{
			root->game->map[j][i] = 0;
			root->game->ndmap[j][i] = 0;
			i++;
		}
		j++;
	}
}

void	map_parsing(t_root *root, char *file)
{
	int	i;
	int	j;
	int	k;
	int	obj;

	obj = 0;
	k = 0;
	j = -1;
	fill_map(root);
	while (++j < root->game->height)
	{
		if (root->game->map[j] == 0)
			free_matrix(root, file, root->game->map, j);
		i = 0;
		while (i < root->game->width)
		{
			get_coord(root, file, k, &obj);
			root->game->map[j][i] = file[k] - '0';
			root->game->ndmap[j][i] = file[k] - '0';
			k++;
			i++;
		}
		k++;
	}
}
