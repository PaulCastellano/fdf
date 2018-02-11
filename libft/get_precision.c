/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:40:48 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:04:42 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_digit(t_format *format, t_tags *tags)
{
	char chr;

	while ((chr = *get_pos(format)) && (ft_isdigit(chr)))
	{
		atoi_add_digit(chr, &(tags->precision));
		format->position++;
	}
}

void	get_precision(t_tags *tags, t_format *format, va_list arg)
{
	char			chr;
	unsigned int	old;

	old = tags->precision;
	if ((chr = *get_pos(format)) == '.')
	{
		tags->set_precision = true;
		format->position++;
		tags->precision = 0;
		if ((chr = *get_pos(format)) == '*')
		{
			tags->precision = va_arg(arg, unsigned int);
			format->position++;
		}
		else
			add_digit(format, tags);
	}
	if (old > tags->precision)
		tags->precision = old;
}
