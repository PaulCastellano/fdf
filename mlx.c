/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 02:00:59 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/17 03:44:02 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_kekmap rot_x(t_kekmap kek)
{
    int x;
    int y;

    y = 0;
    while (y < kek.mapy)
    {
        x = 0;
        while (x < kek.mapx)
        {
            kek.map[y][x].y -= (cos(10) * kek.map[y][x].y - sin(10) * kek.map[y][x].z);
            kek.map[y][x].z = sin(10) * kek.map[y][x].y + cos(10) * kek.map[y][x].z;
            x++;
        }
        y++;
    }
    return (kek);
}

t_kekmap rot_y(t_kekmap kek)
{
    int x;
    int y;

    y = 0;
    while (y < kek.mapy)
    {
        x = 0;
        while (x < kek.mapx)
        {
            kek.map[y][x].x = cos(10) * kek.map[y][x].x + sin(10) * kek.map[y][x].z;
            kek.map[y][x].z = cos(10) * kek.map[y][x].z - sin(10) * kek.map[y][x].x ;
            x++;
        }
        y++;
    }
    return (kek);
}

t_kekmap rot_z(t_kekmap kek)
{
    int x;
    int y;

    y = 0;
    while (y < kek.mapy)
    {
        x = 0;
        while (x < kek.mapx)
        {
            kek.map[y][x].x = cos(10) * kek.map[y][x].x - sin(10) * kek.map[y][x].y;
            kek.map[y][x].y = sin(10) * kek.map[y][x].x + cos(10) * kek.map[y][x].y;
            kek.map[y][x].x = kek.map[y][x].x;
            kek.map[y][x].x = kek.map[y][x].y;
            ft_printf("|%d - %d| ", kek.map[y][x].x, kek.map[y][x].y);
            x++;
        }
        ft_printf("\n");
        y++;
    }
    return (kek);
}

void linelow(int x0, int y0, int x1, int y1, void *mlx_win, void *mlx_ptr)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy *= -1;
    }
    int D = 2 * dy - dx;
    int y = y0;
    int x = x0;
    while (x < x1)
    {
        mlx_pixel_put (mlx_ptr, mlx_win, x, y, 0xFF0000);
        if (D > 0)
        {
            y = y + yi;
            D = D - 2*dx;
        }
        D = D + 2 * dy;
        x++;
    }
}

void linehigh(int x0, int y0, int x1, int y1, void *mlx_win, void *mlx_ptr)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    if (dx < 0)
    {
        xi = -1;
        dx *= -1;
    }
    int D = 2 * dx - dy;
    int x = x0;
    int y = y0;
    while (y < y1)
    {
        mlx_pixel_put (mlx_ptr, mlx_win, x, y, 0xE3E935);
        if (D > 0)
        {
            x = x + xi;
            D = D - 2 * dy;
        }
        D = D + 2 * dx;
        y++;
    }
}

void line(int x0, int y0, int x1, int y1, void *mlx_win, void *mlx_ptr)
{
    if (abs(y1 - y0) < abs(x1 - x0))
        if (x0 > x1)
            linelow(x1, y1,x0,y0, mlx_win, mlx_ptr);
        else
            linelow(x0,y0,x1,y1, mlx_win, mlx_ptr);
    else if (y0 > y1)
        linehigh(x1,y1,x0,y0, mlx_win, mlx_ptr);
    else
        linehigh(x0,y0,x1,y1,mlx_win, mlx_ptr);
}

void draw_line(t_kekmap kek)
{
    int y;
    int x;
    
    y = 0;
    while (y < kek.mapy)
    {
        x = 0;
        while (x < kek.mapx - 1)
        {
            line(kek.map[y][x].x, kek.map[y][x].y, kek.map[y][x + 1].x, kek.map[y][x + 1].y, kek.mlx_win, kek.mlx_ptr);
            x++;
        }
        y++;
    }
    y = 0;
    while (y < kek.mapy - 1)
    {
        x = 0;
        while (x < kek.mapx)
        {
            line(kek.map[y][x].x, kek.map[y][x].y, kek.map[y + 1][x].x, kek.map[y + 1][x].y, kek.mlx_win, kek.mlx_ptr);
            x++;
        }
        y++;
    }
}

void    clear(t_kekmap kek)
{
    mlx_clear_window(kek.mlx_ptr, kek.mlx_win);
}

int key_hook(int keycode, void *param)
{
    if (keycode == 53)
        exit(1);
    if (keycode == 126)
    {
        clear(*(t_kekmap*)param);
        rot_z(*(t_kekmap*)param);
        draw_line(*(t_kekmap*)param);
    }
    if (keycode == 123)
    {
        clear(*(t_kekmap*)param);
        rot_x(*(t_kekmap*)param);
        draw_line(*(t_kekmap*)param);
    }
    if (keycode == 124)
    {
        clear(*(t_kekmap*)param);
        rot_y(*(t_kekmap*)param);
        draw_line(*(t_kekmap*)param);
    }
    return (0);
}


void    ft_kek(t_kekmap kek)
{
    int     x;
    int     y;
    int     mlx_l;
    
    kek.mlx_ptr = mlx_init();
    kek.mlx_win = mlx_new_window(kek.mlx_ptr, 1000, 1000, "fdf");
    kek.map[0][0].x = 500 - kek.mapx * 25 / 2;
    kek.map[0][0].y = 500 - kek.mapy * 25 / 2;
    y = 0;
    while (y < kek.mapy)
    {
        x = 0;
        if (y != 0)
            kek.map[y][x].y = kek.map[y - 1][x].y + 25;
        while (x < kek.mapx)
        {
            if (x != 0)
            {
                kek.map[y][x].x = kek.map[y][x - 1].x + 25;
                kek.map[y][x].y = kek.map[y][x - 1].y;
            }
            x++;
        }
        y++;
        if (y != kek.mapy)
            kek.map[y][0].x = kek.map[y - 1][0].x;
    }
    draw_line(kek);
    mlx_hook(kek.mlx_win, 2, 3, key_hook, &kek);
    /*y = v2 / kek.mapy;
    while (y <= v2)
    {
        x = v1 / kek.mapx;
        while (x <= v1)
        {
            mlx_pixel_put (mlx_ptr, mlx_win, x + 375, y + 375, 0xE3E935);
            x += 25;
        }
        y++;
    }*/
    mlx_l = mlx_loop(kek.mlx_ptr);
}