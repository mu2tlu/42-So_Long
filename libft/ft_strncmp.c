/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:04:43 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:04:44 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i] && (i < n - 1) && (s1[i] != '\0' && s2[i] != '\0'
				&& s2[i] != '\0')))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
