/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:08:17 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/16 17:23:53 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include <stdlib.h> /*
#   void free(void *);
*/

void	ft_freematrix(char **matrix)
{
	int x;

	x = -1;
	while (matrix[x])
	{
		free(matrix[x]);
		matrix[x] = (void *)0;
	}
	free(matrix);
	matrix = (void *)0;
}

int	ft_matrixlen(char **matrix)
{
	int ecx;

	ecx = 0;
	while (matrix[ecx])
		++ecx;
	return (ecx);
}

#include <stdlib.h> /*
#   void *malloc(int);
*/

char	**ft_matrixdup(char **matrix)
{
	int		x;
	int		y;
	char	**result;

	y = 0;
	while (matrix[y])
		++y;
	result = (char **)malloc((y + 1) * sizeof(char *));
	if (!result)
		return ((void *)0);
	y = -1;
	while (++y, matrix[y])
	{
		result[y] = (char *)malloc(sizeof(char) * (ft_strlen(matrix[y])));
		if (!result[y])
			ft_freematrix(result);
		if (!result[y])
			return ((void *)0);
		x = -1;
		while (++x, matrix[y][x])
			result[y][x] = matrix[y][x];
		result[y][x] = 0;
	}
	result[y] = (void *)0;
	return (result);
}