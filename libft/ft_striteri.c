/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:03:57 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:03:58 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*ft_func)(unsigned int, char*))
{
	unsigned int	index;

	if (str)
	{
		index = 0;
		while (*str)
			ft_func(index++, str++);
	}
}
