/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:02:39 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:02:40 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 1;
	if (lst)
	{
		temp = lst;
		while (temp->next)
		{
			temp = temp->next;
			i++;
		}
		return (i);
	}
	return (0);
}
