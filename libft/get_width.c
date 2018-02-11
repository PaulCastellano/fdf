/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:41:06 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:05:06 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_width(t_tags *tags, t_format *format, va_list arg)
{
	char			chr;
	unsigned int	old;

	old = tags->width;
	if ((chr = *get_pos(format)) == '*')
	{
		tags->width = va_arg(arg, unsigned int);
		format->position++;
	}
	else if ((chr = *get_pos(format)) && !ft_isdigit(chr))
		tags->width = 0;
	else
	{
		while ((chr = *get_pos(format)) && (ft_isdigit(chr)))
		{
			atoi_add_digit(chr, &(tags->width));
			format->position++;
		}
	}
	if (old > tags->width)
		tags->width = old;
}
