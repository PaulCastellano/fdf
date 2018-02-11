/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:50:54 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/03 11:50:54 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char*)src;
	d = (char*)dest;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (char)c)
			return ((void*)&d[i + 1]);
		i++;
	}
	return (NULL);
}
