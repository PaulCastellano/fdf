/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:47:05 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/03 11:47:06 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, size_t nbr)
{
	size_t i;

	i = 1;
	while (i < nbr && begin_list->next != 0)
	{
		i++;
		begin_list = begin_list->next;
	}
	if (i == nbr)
		return (begin_list);
	else
		return (0);
}
