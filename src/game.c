/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:07:19 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/17 16:40:17 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"
#include "../libs/mlx/mlx.h"
#include "../libs/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	load_sprite(t_game game)
{
	int	tmp_x;
	int	tmp_y;

	game->dipper_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/dipper.xpm", &tmp_x, &tmp_y);
	game->wall_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/wall.xpm", &tmp_x, &tmp_y);
	game->floor_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/floor.xpm", &tmp_x, &tmp_y);
	game->coin_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/coin.xpm", &tmp_x, &tmp_y);
	game->exit_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/exit.xpm", &tmp_x, &tmp_y);
}

static int	filename_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
	{
		return (0);
	}
	write(1, "ERROR\n", 6);
	return (1);
}

static void	game_init(t_game game)
{
	game->coins = 0;
	game->exit = 0;
	game->ply = 0;
	game->moves = 0;
}

void	start_game(char *map_name)
{
	struct s_game	game;
	int				fd;

	if (filename_check(map_name))
		return ;
	game_init(&game);
	fd = open(map_name, O_RDONLY);
	game.map = map_constructor(fd);
	close(fd);
	if (map_validation(&game))
	{
		write(1, "ERROR\n", 6);
		ft_freematrix(game.map);
		exit(1);
	}
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, ft_strlen(game.map[0]) * PIXEL,
			ft_matrixlen(game.map) * PIXEL, "so_long");
	load_sprite(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_down, &game);
	mlx_hook(game.mlx_win, 17, 0L << 0, game_exit, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
}
