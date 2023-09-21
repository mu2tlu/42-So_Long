/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:07:21 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/22 02:27:46 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
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
	if (!(game->dipper_sprite
			&& game->wall_sprite && game->wall_sprite
			&& game->coin_sprite && game->exit_sprite))
	{
		write(2, "Error\n.xpm File extension is not correct\n", 41);
		game_exit(game);
	}
}

static void	game_init(t_game game)
{
	game->dipper_sprite = NULL;
	game->wall_sprite = NULL;
	game->floor_sprite = NULL;
	game->coin_sprite = NULL;
	game->exit_sprite = NULL;
	game->coins = 0;
	game->exit = 0;
	game->ply = 0;
	game->moves = 0;
}

void	start_game(char *map_name)
{
	struct s_game	game;
	int				fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit((write(2, "Error\nFile could not be opened\n", 31), 1));
	game.map = map_constructor(fd);
	close(fd);
	if (!game.map && game.map == NULL)
		exit((write(2, "Error\nMap not loaded\n", 21), 1));
	game_init(&game);
	if (map_validation(&game))
	{
		write(2, "Error\nMap not suitable\n", 23);
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
