/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:07:19 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/03 12:07:19 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	int		i;
	int		j;

	str = (char*)haystack;
	i = 0;
	if (!*needle)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == needle[j])
		{
			if (!(needle[j + 1]))
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
