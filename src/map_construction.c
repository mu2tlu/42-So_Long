/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_construction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:07:42 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/19 16:12:38 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

char	**map_constructor(int fd)
{
	char	*line;
	char	*temp;
	char	*map_out;
	char	**result;

	temp = get_next_line(fd);
	line = malloc(2 * sizeof(char));
	while (!!temp)
	{
		map_out = ft_strjoin(line, temp);
		if (line)
			free(line);
		free(temp);
		temp = get_next_line(fd);
		if (map_out)
			line = ft_strdup(map_out);
		free(map_out);
		map_out = (void *)0;
	}
	free(temp);
	temp = (void *)0;
	result = ft_split(line, '\n');
	free(line);
	return (result);
}
