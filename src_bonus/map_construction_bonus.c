/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_construction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:07:58 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/23 01:44:39 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>

static char	*map_joinner(int fd)
{
	char	*map_out;
	char	*temp;
	char	*line;

	temp = get_next_line(fd);
	if (temp == NULL)
		return (NULL);
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
			map_out = (free(map_out), (void *)0);
	}
	if (temp)
		temp = (free(temp), (void *)0);
	return (line);
}

static int	check_breaker(char *line)
{
	int		len;
	int		i;

	len = (int)ft_strlen(line) - 1;
	while (line[len] == '\n')
	{
		if (0 == len)
			return (1);
		len--;
	}
	i = 0;
	while (line[i] == '\n')
		i++;
	while (i < len)
	{
		if (i + 1 == len)
			return (0);
		else if (line[i] == '\n' && line[i + 1] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	**map_constructor(int fd)
{
	char	*line;
	char	**result;

	line = map_joinner(fd);
	if (line == NULL)
		return (NULL);
	if (check_breaker(line))
	{
		free(line);
		close(fd);
		exit((write(2, "Error\nMap not up to standard\n", 29), 1));
	}
	result = ft_split(line, '\n');
	if (line)
		free(line);
	return (result);
}
