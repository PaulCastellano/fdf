/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 23:35:30 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 13:52:02 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listaddb(t_lst *lst, t_lst *new)
{
	if (lst != NULL && new != NULL)
	{
		lst->next = new;
		new->prec = lst;
	}
}

t_lst	*ft_listnew(int fd)
{
	t_lst *l;

	if (!(l = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	l->s = NULL;
	l->fd = fd;
	l->next = NULL;
	return (l);
}

int		helper(char **line, t_lst *buffstat)
{
	char			*str;

	str = NULL;
	if (buffstat->s != NULL)
	{
		str = ft_strchr(buffstat->s, '\n');
		if (str != NULL)
		{
			*str = '\0';
			*line = ft_strdup(buffstat->s);
			buffstat->s = ft_strdup(str + 1);
			return (1);
		}
		if (0 < ft_strlen(buffstat->s))
		{
			*line = ft_strdup((buffstat->s));
			*(buffstat)->s = '\0';
			return (1);
		}
	}
	*line = ft_strnew(0);
	return (0);
}

t_lst	*listfunction(t_lst *buffstat, int fd)
{
	while ((int)buffstat->fd < fd && buffstat)
	{
		if (!buffstat->next)
			ft_listaddb(buffstat, ft_listnew(fd));
		buffstat = buffstat->next;
		if ((int)buffstat->fd == fd)
			return (buffstat);
	}
	while ((int)buffstat->fd > fd && buffstat)
	{
		buffstat = buffstat->prec;
		if ((int)buffstat->fd == fd)
			return (buffstat);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*buffstat;
	char			buf[BUFF_SIZE + 1];
	int				kek;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0 || fd >= MAX_FD)
		return (-1);
	if (buffstat && (int)buffstat->fd != fd && fd)
		buffstat = listfunction(buffstat, fd);
	if (buffstat == NULL)
		buffstat = ft_listnew(fd);
	*line = 0;
	while ((kek = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[kek] = '\0';
		buffstat->s = ft_strjoinfree(buffstat->s, buf, 1);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (kek < 0)
		return (-1);
	return (helper(line, buffstat));
}
