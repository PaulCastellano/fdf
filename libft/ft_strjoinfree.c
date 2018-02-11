/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 02:36:03 by egaraz            #+#    #+#             */
/*   Updated: 2017/12/30 02:36:16 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int f)
{
	char	*s3;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s3)
	{
		ft_strcpy(s3, s1);
		ft_strcat(s3, s2);
	}
	if (f == 1)
		ft_strdel(&s1);
	else if (f == 2)
		ft_strdel(&s2);
	return (s3);
}
