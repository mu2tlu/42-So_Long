/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:01:39 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:01:40 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dizi;
	long	nbr;

	nbr = n;
	len = numlen(nbr);
	dizi = malloc(sizeof(char) * len + 1);
	if (!dizi)
		return (0);
	dizi[len--] = '\0';
	if (n < 0)
	{
		dizi[0] = '-';
		nbr = -nbr;
	}
	if (n == 0)
		dizi[0] = '0';
	while (nbr > 0)
	{
		dizi[len--] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (dizi);
}
