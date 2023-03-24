/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:04:23 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:04:23 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	x;

	x = 0;
	if (n > 0)
	{
		while (src [x] != '\0' && x < (n - 1))
		{
			dst[x] = src [x];
			x++;
		}
		dst[x] = 0;
	}
	while (src[x])
		x++;
	return (x);
}
