/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:40:00 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:04:50 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_specifier		add_specifier(char chr)
{
	if (chr == 'd' || chr == 'i' || chr == 'D')
		return (DECIMAL);
	if (chr == 's' || chr == 'S')
		return (STRING);
	if (chr == 'p')
		return (POINTER);
	if (chr == 'x')
		return (HEX_LOWER);
	if (chr == 'X')
		return (HEX_UPPER);
	if (chr == 'u' || chr == 'U')
		return (U_DECIMAL);
	if (chr == 'o' || chr == 'O')
		return (OCTAL);
	if (chr == 'c' || chr == 'C')
		return (CHAR);
	if (chr == '%')
		return (PERCENT);
	return (INVALID);
}

void			get_specifier(t_tags *tags, t_format *format)
{
	char chr;

	if ((chr = *get_pos(format)) != '\0')
		tags->specifier = add_specifier(chr);
	if (tags->specifier == U_DECIMAL)
	{
		tags->flags.sign = false;
		tags->flags.space = false;
	}
	if (chr == 'U' || chr == 'O' || chr == 'D' || chr == 'C' || chr == 'S')
		tags->length = L;
	if (tags->specifier != INVALID)
		format->position++;
}
