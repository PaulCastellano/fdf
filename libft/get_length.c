/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:39:52 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:04:30 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_length	add_length(char chr, char chr2)
{
	if (chr == 'h')
		return (chr2 == 'h' ? HH : H);
	if (chr == 'l')
		return (chr2 == 'l' ? LL : L);
	if (chr == 'z')
		return (Z);
	if (chr == 'j')
		return (J);
	return (DEFAULT);
}

void		get_length(t_tags *tags, t_format *format)
{
	char		chr;
	char		chr2;
	t_length	old;

	old = tags->length;
	if ((!(chr = *get_pos(format))))
		return ;
	chr2 = *(get_pos(format) + 1);
	tags->length = add_length(chr, chr2);
	if (tags->length != DEFAULT)
		format->position++;
	if (tags->length == HH || tags->length == LL)
		format->position++;
	if (old > tags->length)
		tags->length = old;
}
