/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:02:49 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:02:50 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dizi1, const void *dizi2, size_t boyut)
{
	size_t	i;

	i = 0;
	while (i < boyut)
	{
		if (((unsigned char *)dizi1)[i] != ((unsigned char *)dizi2)[i])
			return (((unsigned char *)dizi1)[i] - ((unsigned char *)dizi2)[i]);
		i++;
	}
	return (0);
}
