/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:03:43 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:03:43 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (c > 255)
		c -= 256;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return ((char *)(str + i));
		i++;
	}
	if (*(str + i) == c)
		return ((char *)str + i);
	return (NULL);
}
