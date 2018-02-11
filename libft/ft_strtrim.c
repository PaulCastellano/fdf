/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:07:42 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/03 12:07:42 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	len;
	char			*str;
	char			*str_new;
	unsigned int	i;

	str = (char*)s;
	if (!str)
		return (NULL);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	len = ft_strlen(str) - 1;
	if (ft_strlen(str) == 0)
		return (str_new = ft_strnew(0));
	while (str[len] == ' ' || str[len] == '\t' || str[len] == '\n')
		len--;
	if (!(str_new = (char*)ft_strnew(len + 1)))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str_new[i++] = *str;
		str++;
	}
	str_new[i] = '\0';
	return (str_new);
}
