/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:05:57 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/21 21:54:30 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 64
#include <stdio.h>

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;

	void			*dipper_sprite;
	void			*floor_sprite;
	void			*wall_sprite;
	void			*coin_sprite;
	void			*exit_sprite;

	int				player_x;
	int				player_y;

	unsigned int	moves;
	char			**map;

	int				exit;
	int				ply;
	int				coins;

	int				exit_is_possible;
}					*t_game;

void				load_sprite(t_game game);
void				start_game(char *map_name);

int					game_exit(t_game game);
int					key_down(int keycode, t_game game);

int					render(t_game game);

char				**map_constructor(int fd);
int					map_validation(t_game sl);
int					flood_fill(t_game game);

void				ft_freematrix(char **matrix);
char				**ft_matrixdup(char **matrix);
int					ft_matrixlen(char **matrix);

#endif