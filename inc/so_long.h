/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:05:57 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/14 18:05:58 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# define PIXEL 64

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
}	*t_game;

void				start_game(char *map_name);

int					key_down(int keycode, t_game game);
int					game_exit(t_game game);

int					render(t_game game);

char				**map_constractor(t_game game, int fd);
int					map_validation(t_game sl);
int					flood_fill(t_game game);

char				*ft_itoa(int n);
void				free_map(char **map);

#endif