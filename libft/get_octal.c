/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:37:55 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:04:29 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_octal(t_tags *tags, va_list arg)
{
	uintmax_t	value;
	char		*octal;
	char		*new_octal;

	value = get_u_value(tags, arg);
	if (!value && tags->set_precision == true)
		octal = ft_strdup("");
	else
		octal = ft_itoa_base(value, 8);
	precision(tags, &octal);
	if (tags->flags.sharp == true &&
		tags->flags.zero == false && octal[0] != '0')
	{
		new_octal = ft_strjoin("0", octal);
		free(octal);
		return (new_octal);
	}
	return (octal);
}
