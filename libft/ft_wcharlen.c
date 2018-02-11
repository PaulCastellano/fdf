/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:07:55 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/03 12:07:57 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wcharlen(wchar_t chr)
{
	if (chr <= 0x7F)
		return (1);
	if (chr <= 0x7FF)
		return (2);
	if (chr <= 0xFFFF)
		return (3);
	if (chr <= 0x10FFFF)
		return (4);
	return (0);
}
