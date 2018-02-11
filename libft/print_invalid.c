/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:42:30 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:05:16 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_invalid(t_tags *tags, t_format *format)
{
	if (tags->set_precision == true || tags->width_precision == true ||
		tags->width > 0)
	{
		if (tags->flags.left_justify == true)
		{
			ft_putchar(*get_pos(format));
			print_width(tags, format, " ");
		}
		else
		{
			print_width(tags, format, " ");
			ft_putchar(*get_pos(format));
		}
		format->position++;
		format->written++;
	}
}

void	print_sign(t_tags *tags, t_format *format, char *str)
{
	ft_putchar(str[0]);
	print_width(tags, format, str);
	ft_putstr(str + 1);
}
