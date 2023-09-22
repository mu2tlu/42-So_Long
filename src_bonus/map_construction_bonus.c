/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_construction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:07:58 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/22 23:29:11 by mumutlu          ###   ########.fr       */
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
	i = 0;
	while (i < len && line[len] == '\n')
	{
		if (i == len - 1)
			return (1);
		len--;
	}
	while (i < len)
	{
		if (!(line[i] == '\n') && i + 1 != len)
		{
			if (line[len + 1] == '\n' || line[len + 1] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
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
