/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:03:52 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:03:53 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*final;
	int		i;

	i = 0;
	final = (char *) malloc(ft_strlen(s1) + 1);
	if (!final)
		return (0);
	while (*(s1 + i))
	{
		*(final + i) = *(s1 + i);
		i++;
	}
	*(final + i) = 0;
	return (final);
}
