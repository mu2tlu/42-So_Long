/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:10:15 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/14 18:10:16 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

char	*ft_itoa(int number)
{
	char	*result;

	int (n) = number;
	int (len) = 0;
	if (number < 0)
		len ++;
	while (n)
	{
		n /= 10;
		len ++;
	}
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (number)
	{
		result[--len] = number % 10 + '0';
		number /= 10;
	}
	return (result);
}
