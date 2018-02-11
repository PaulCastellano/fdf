/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:38:06 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:04:28 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_pointer(t_tags *tags, va_list arg)
{
	uintmax_t	value;
	char		*pointer;
	char		*pointer2;

	value = (long)va_arg(arg, void*);
	if (value == 0 && tags->set_precision == true)
		pointer = ft_strdup("");
	else
		pointer = ft_itoa_base(value, 16);
	ft_strtolower(pointer);
	precision(tags, &pointer);
	pointer2 = ft_strjoin("0x", pointer);
	free(pointer);
	return (pointer2);
}
