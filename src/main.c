/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:07:35 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/20 15:26:13 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "unistd.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		start_game(av[1]);
	else
		write(1, "please enter 2 arguments\n", 26);
	return (0);
}
