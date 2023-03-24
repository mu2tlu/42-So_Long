/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:05:59 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/24 13:41:12 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(char *msg)
{
	ft_printf("%s", msg);
	exit (0);
}

int	mouse_hook(int mousecode, t_data *data)
{
	(void)mousecode;
	(void)data;
	err_msg("Exit Success");
	return (0);
}

int	exit_door(t_data *data)
{
	if (data->coin_collected == data->coin_count)
	{
		ft_printf("\n>>>>Toplam Hareket: %d\n", data->step_count);
		err_msg("FINISH");
	}
	else if (data->coin_collected != data->coin_count)
		return (1);
	return (0);
}
