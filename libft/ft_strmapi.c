/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:06:36 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/03 12:06:36 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*str_new;

	str = (char*)s;
	if (str && f)
	{
		i = 0;
		str_new = ft_strnew(ft_strlen(str));
		if (!str_new)
			return (NULL);
		while (str[i])
		{
			str_new[i] = (*f)(i, str[i]);
			i++;
		}
		return (str_new);
	}
	return (NULL);
}
