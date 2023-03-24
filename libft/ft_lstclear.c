/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:02:00 by sekilinc          #+#    #+#             */
/*   Updated: 2023/03/22 12:02:01 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		temp = temp->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(temp);
}
