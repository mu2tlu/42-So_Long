/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:00:40 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:00:41 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		n;

	n = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0') * n;
		if (result > 2147483647)
			return (-1);
		if (result < -2147483648)
			return (0);
		str++;
	}
	return (result);
}
