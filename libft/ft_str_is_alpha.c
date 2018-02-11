/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:05:07 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/03 12:05:13 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		validare(char c)
{
	if ((c < 123 && c > 96) || (c < 91 && c > 64))
		return (1);
	else
		return (0);
}

int				ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (validare(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
