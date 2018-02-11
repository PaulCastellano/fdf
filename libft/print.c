/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:38:59 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 14:09:31 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_str(t_tags *tags, va_list arg)
{
	if (tags->specifier == STRING)
		return (get_string(tags, arg));
	if (tags->specifier == OCTAL)
		return (get_octal(tags, arg));
	if (tags->specifier == POINTER)
		return (get_pointer(tags, arg));
	if (tags->specifier == HEX_LOWER || tags->specifier == HEX_UPPER)
		return (get_hex(tags, arg));
	return (get_decimal(tags, arg));
}

void	print_width(t_tags *tags, t_format *format, char *str)
{
	int		n;
	char	chr;

	if (tags->flags.zero == true)
		chr = '0';
	else
		chr = ' ';
	n = tags->width - ft_strlen(str);
	while (n > 0)
	{
		ft_putchar(chr);
		format->written++;
		n--;
	}
}

void	print_char(t_tags *tags, t_format *format, char chr)
{
	if (tags->flags.left_justify == false)
	{
		print_width(tags, format, " ");
		ft_putchar(chr);
	}
	else
	{
		ft_putchar(chr);
		print_width(tags, format, " ");
	}
	format->written++;
}

void	print_format(t_tags *tags, t_format *format, va_list arg)
{
	char	*str;

	str = get_str(tags, arg);
	if (tags->flags.left_justify == false)
	{
		if (tags->flags.zero == true && !ft_isdigit(str[0])
			&& tags->specifier != STRING && tags->specifier != HEX_UPPER &&
			tags->specifier != HEX_LOWER)
			print_sign(tags, format, str);
		else
		{
			print_width(tags, format, str);
			ft_putstr(str);
		}
	}
	else
	{
		ft_putstr(str);
		print_width(tags, format, str);
	}
	format->written += ft_strlen(str);
	free(str);
}

void	print(t_tags *tags, t_format *format, va_list arg)
{
	if (tags->specifier == PERCENT)
		print_char(tags, format, '%');
	else if (tags->specifier == INVALID)
		print_invalid(tags, format);
	else if (tags->specifier == CHAR)
	{
		if (tags->length >= L)
			print_wchar(tags, format, (wchar_t)va_arg(arg, wint_t));
		else
			print_char(tags, format, va_arg(arg, int));
	}
	else if (tags->specifier == STRING && tags->length >= L)
		print_wstr(tags, format, arg);
	else
		print_format(tags, format, arg);
}
