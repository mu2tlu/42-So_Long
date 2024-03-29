/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:08:00 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/21 16:24:24 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static char	check_objects(char **map)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
		{
			c = map[y][x];
			if (c == 'C' || c == 'E' || c == 'P')
				return (1);
		}
	}
	return (0);
}

static void	check_path(char **map, size_t y, size_t x)
{
	map[y][x] = '1';
	if (map[y + 1][x] != '1')
		check_path(map, y + 1, x);
	if (map[y - 1][x] != '1')
		check_path(map, y - 1, x);
	if (map[y][x + 1] != '1')
		check_path(map, y, x + 1);
	if (map[y][x - 1] != '1')
		check_path(map, y, x - 1);
}

int	flood_fill(t_game game)
{
	char	**map;

	map = ft_matrixdup(game->map);
	if (!map)
		return (1);
	check_path(map, game->player_y, game->player_x);
	if (check_objects(map))
	{
		ft_freematrix(map);
		return (1);
	}
	ft_freematrix(map);
	return (0);
}
