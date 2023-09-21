/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_construction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:07:42 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/21 15:43:03 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

static char	*map_joinner(int fd);
static int	check_breaker(char *line);

char	**map_constructor(int fd)
{
	char	*line;
	char	**result;

	line = map_joinner(fd);
	if (check_breaker(line))
	{
		free(line);
		return ((void *)0);
	}
	result = ft_split(line, '\n');
	if (line)
		free(line);
	return (result);
}

static char	*map_joinner(int fd)
{
	char	*map_out;
	char	*temp;
	char	*line;

	temp = get_next_line(fd);
	line = (char [2]){0, 0};
	while (!!temp)
	{
		map_out = ft_strjoin(line, temp);
		if (line[0])
			free(line);
		if (!!temp)
			free(temp);
		temp = get_next_line(fd);
		if (!!map_out)
			line = ft_strdup(map_out);
		if (!!map_out)
			free(map_out);
		map_out = (void *)0;
	}
	if (temp)
		free(temp);
	temp = (void *)0;
	return (line);
}

static int	check_breaker(char *line)
{
	register int	ecx;
	register int	line_size;
	register char	only_newline;

	ecx = -1;
	line_size = 0;
	only_newline = 0;
	while (++ecx, line[ecx])
	{
		line_size = 0;
		while (line[line_size + ecx] != '\n' && !!line[line_size + ecx])
			++line_size;
		if (line_size == 0)
			only_newline = 1;
		if (!!line_size && only_newline)
			return (1);
		ecx += line_size;
	}
	return (0);
}
