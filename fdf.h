/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:38:41 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/11 05:50:38 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct  s_kek
{
    int x;
    int y;
    int **tab;
}               t_kek;

int     valid_map(char *str, int aux);
int     check_line(char *line, int i);
t_kek   maloc_array(t_kek kek, char *str);
t_kek   array(t_kek kek, int col, int ln, int fd, char *s);
void    ft_kek(t_kek kek);

#endif