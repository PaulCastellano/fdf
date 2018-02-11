/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:37:09 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:02:01 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char *str, ...)
{
	va_list		arg;
	t_format	format;

	ft_bzero(&format, sizeof(t_format));
	format.str = str;
	va_start(arg, str);
	analyse_format(&format, arg);
	va_end(arg);
	return (format.written);
}
