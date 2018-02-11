/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:39:43 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:04:32 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_flag(t_bool *flag, t_format *format)
{
	*flag = true;
	format->position++;
}

void	get_flags(t_tags *tags, t_format *format)
{
	char chr;

	while ((chr = *get_pos(format)) &&
			(chr == '0' || chr == '+' || chr == '#' || chr == '-' ||
			chr == '-' || chr == ' '))
	{
		if (chr == '0')
			check_flag(&(tags->flags.zero), format);
		if (chr == '+')
			check_flag(&(tags->flags.sign), format);
		if (chr == '#')
			check_flag(&(tags->flags.sharp), format);
		if (chr == '-')
			check_flag(&(tags->flags.left_justify), format);
		if (chr == ' ')
			check_flag(&(tags->flags.space), format);
	}
}
