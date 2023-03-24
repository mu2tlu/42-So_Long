/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:05:06 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:05:07 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s;
	size_t	e;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	e = ft_strlen(s1);
	while (s1[s] && ft_check(s1[s], set))
		s++;
	while (e > s && ft_check(s1[e -1], set))
		e--;
	str = (char *)malloc(sizeof(char) * (e - s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s < e)
		str[i++] = s1[s++];
	str[i] = '\0';
	return (str);
}
