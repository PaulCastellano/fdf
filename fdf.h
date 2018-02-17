/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:38:41 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/16 23:26:49 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct s_vector
{
    int x;
    int y;
    int z;
    int x1;
    int y1;
    int z1;
}               t_vector;

typedef struct  s_kek
{
    int x;
    int y;
    int z;
}               t_kek;

typedef struct  s_kekmap
{
    int     mapy;
    int     mapx;
    int     mapz;
    t_kek   **map;
    void    *mlx_win;
    void    *mlx_ptr;
}               t_kekmap;

int         valid_map(char *str, int aux);
int         check_line(char *line, int i);
t_kekmap    maloc_array(t_kekmap kek, char *str);
t_kekmap    array(t_kekmap kek, int col, int ln, int fd, char *s);
void        ft_kek(t_kekmap kek);
void line(int x0, int y0, int x1, int y1, void *mlx_win, void *mlx_ptr);
void linehigh(int x0, int y0, int x1, int y1, void *mlx_win, void *mlx_ptr);
void linelow(int x0, int y0, int x1, int y1, void *mlx_win, void *mlx_ptr);
void rot_x(t_vector *kek);
void rot_y(t_vector *kek);
void rot_z(t_vector *kek);
void    scale(t_vector kek, t_kekmap m);
void    rot(t_kekmap kek);
#endif