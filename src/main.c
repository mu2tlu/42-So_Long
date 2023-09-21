/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:07:35 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/21 21:39:09 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "unistd.h"

static int	filename_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
	{
		return (1);
	}
	write(2, "ERROR\nFile extension is not correct\n", 36);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (filename_check(av[1]))
			start_game(av[1]);
	}
	else
		write(2, "Error\nPlease enter 2 arguments\n", 31);
	return (0);
}
