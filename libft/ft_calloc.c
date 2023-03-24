/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:00:57 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:00:58 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t countbyte)
{
	void	*p;

	p = malloc(count * countbyte);
	if (!p)
		return (0);
	ft_bzero(p, count * countbyte);
	return (p);
}
