/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 02:00:59 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/11 07:42:42 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void    ft_kek(t_kek kek)
{
    int     v1;
    int     v2;
    int     x;
    int     y;
    int     mlx_l;
    void    *mlx_ptr;
    void    *mlx_win;
    
    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 1000, 1000, "fdf");
    y = 0;
    v2 = 0;
    while (y < kek.y)
    {
        x = 0;
        v1 = 0;
        while (x < kek.x)
        {
            v1 = v1 + 25;
            x++;
        }
        v2 = v2 + 25;
        y++;
    }
    y = v2 / kek.y;
    while (y <= v2)
    {
        x = v1 / kek.x;
        while (x <= v1)
        {
            mlx_pixel_put (mlx_ptr, mlx_win, x + 375, y + 375, 0xE3E935);
            x++;
        }
        y += 25;
    }
    y = v2 / kek.y;
    while (y <= v2)
    {
        x = v1 / kek.x;
        while (x <= v1)
        {
            mlx_pixel_put (mlx_ptr, mlx_win, x + 375, y + 375, 0xE3E935);
            x += 25;
        }
        y++;
    }
    mlx_l = mlx_loop(mlx_ptr);
}