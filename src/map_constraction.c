/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:07:42 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/14 18:07:43 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

char	**map_constractor(t_game game, int fd)
{
	char	**result;
	char	*buffer;
	char	*temp;
	char	*temp2;

	buffer = get_next_line(fd);
	temp2 = (void *)0;
	temp = (void *)0;
	while(ft_strlen(buffer))
	{
		if (!!temp2)
			temp = ft_strdup(temp2);
		if (!!temp2)
			free(temp2);
		temp2 = strjoin(temp, buffer);
		free(temp);
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (buffer)
		free(buffer);
	result = ft_split(temp, '\n');
	free(temp2);
	return (result);
}
