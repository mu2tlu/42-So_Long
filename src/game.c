/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:07:19 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/21 15:41:58 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
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
	if (!(game->dipper_sprite
			&& game->wall_sprite && game->wall_sprite
			&& game->coin_sprite && game->exit_sprite))
	{
		write(1, "ERROR\n", 7);
		game_exit(game);
	}
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
	write(1, "ERROR\n", 7);
	return (1);
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

	if (filename_check(map_name))
		return ;
	fd = open(map_name, O_RDONLY);
	game.map = map_constructor(fd);
	close(fd);
	if (!game.map)
		exit((write(1, "ERROR\n", 7), 1));
	game_init(&game);
	if (map_validation(&game))
	{
		write(1, "ERROR\n", 7);
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
