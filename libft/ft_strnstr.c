/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:07:06 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/03 12:07:07 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	len;

	if (*to_find == '\0')
		return ((char *)str);
	len = ft_strlen(to_find);
	while (*str != '\0' && n >= len)
	{
		if (ft_strncmp(str, to_find, len) == 0)
			return ((char *)str);
		str++;
		n--;
	}
	return (NULL);
}
