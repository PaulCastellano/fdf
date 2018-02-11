/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:46:49 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/03 11:46:49 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(intmax_t n)
{
	size_t			i;
	uintmax_t		nbr;

	i = 0;
	if (n < 0)
	{
		i++;
		nbr = (uintmax_t)-n;
	}
	else
		nbr = (uintmax_t)n;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char		*ft_str_itoa(intmax_t n, char *str, size_t len)
{
	uintmax_t		nbr;
	char			*s;

	s = str;
	nbr = 0;
	if (n < 0)
	{
		nbr = (uintmax_t)-n;
		s[0] = '-';
	}
	else
		nbr = (uintmax_t)n;
	while (nbr > 0)
	{
		len--;
		s[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (s);
}

char			*ft_itoa_large(intmax_t n)
{
	char	*str;
	size_t	len;

	len = nbr_len(n);
	if (n == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = '0';
	}
	else
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		str = ft_str_itoa(n, str, len);
	}
	return (str);
}
