/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:39:30 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:01:38 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_pos(t_format *format)
{
	return (format->str + format->position);
}

t_bool	check_percent(t_format *format)
{
	char	chr;

	if ((chr = *get_pos(format)) == '%')
	{
		ft_putchar('%');
		format->position++;
		format->written++;
		return (true);
	}
	return (false);
}

void	get_tags(t_tags *tags, t_format *format, va_list arg)
{
	while (is_tag(*get_pos(format)))
	{
		get_flags(tags, format);
		get_width(tags, format, arg);
		get_precision(tags, format, arg);
		get_length(tags, format);
		tags->iter++;
	}
	get_specifier(tags, format);
	validate_flags(tags);
}

void	analyse_tags(t_format *format, va_list arg)
{
	t_tags tags;

	if (check_percent(format))
		return ;
	ft_bzero(&tags, sizeof(t_tags));
	get_tags(&tags, format, arg);
	print(&tags, format, arg);
}

void	analyse_format(t_format *format, va_list arg)
{
	char chr;

	while ((chr = *get_pos(format)) != '\0')
	{
		if (chr == '%')
		{
			format->position++;
			analyse_tags(format, arg);
		}
		else
		{
			ft_putchar(chr);
			format->position++;
			format->written++;
		}
	}
}
