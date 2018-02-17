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

void rot_x(t_vector *kek)
{
    kek->y = cos(10) * kek->y - sin(10) * kek->z;
    kek->z = sin(10) * kek->y + cos(10) * kek->z;
    kek->y1 = cos(10) * kek->y1 - sin(10) * kek->z1;
    kek->z1= sin(10) * kek->y1 + cos(10) * kek->z1;
}

void rot_y(t_vector *kek)
{
    kek->x = cos(10) * kek->x + sin(10) * kek->z;
    kek->z = -sin(10) * kek->x + cos(10) * kek->z;
    kek->x1 = cos(10) * kek->x1 + sin(10) * kek->z1;
    kek->z1 = -sin(10) * kek->x1 + cos(10) * kek->z1;
}

void rot_z(t_vector *kek)
{
    kek->x = cos(10) * kek->x - sin(10) * kek->y;
    kek->y = sin(10) * kek->x + cos(10) * kek->y;
    kek->x1 = cos(10) * kek->x1 - sin(10) * kek->y1;
    kek->y1 = sin(10) * kek->x1 + cos(10) * kek->y1;
}

void linelow(int x0, int y0, int x1, int y1, void *mlx_win, void *mlx_ptr)
{
    ft_printf("low\n");
    int dx;
    int dy;
    int yi;
    dy = y1 - y0;
    yi = 1;
    dx = x1 - x0;
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
        ft_printf("low while\n");
        mlx_pixel_put (mlx_ptr, mlx_win, x + 500, y + 500, 0xFF0000);
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
    ft_printf("high\n");
    int dx;
    int dy;
    int xi;
    xi = 1;
    dy = y1 - y0;
    dx = x1 - x0;
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
        ft_printf("%d\n", y);
        mlx_pixel_put (mlx_ptr, mlx_win, x + 500, y + 500, 0xE3E935);
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
    ft_printf("inceput\n");
    if (abs(y1 - y0) < abs(x1 - x0))
    {
        if (x0 > x1)
            linelow(x1, y1,x0,y0, mlx_win, mlx_ptr);
        else
            linelow(x0,y0,x1,y1, mlx_win, mlx_ptr);
    }
    else if (y0 > y1)
        linehigh(x1,y1,x0,y0, mlx_win, mlx_ptr);
    else
        linehigh(x0,y0,x1,y1,mlx_win, mlx_ptr);
    ft_printf("sfirsit line");
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
        //rot_z(*(t_kekmap*)param);
        //draw_line(*(t_kekmap*)param);
    }
    if (keycode == 123)
    {
        clear(*(t_kekmap*)param);
        //rot_x(*(t_kekmap*)param);
        //draw_line(*(t_kekmap*)param);
    }
    if (keycode == 124)
    {
        clear(*(t_kekmap*)param);
        //rot_y(*(t_kekmap*)param);
        //draw_line(*(t_kekmap*)param);
    }
    return (0);
}

void    scale(t_vector kek, t_kekmap m)
{
    kek.x *= 25;
    kek.y *= 25;
    kek.x1 *= 25;
    kek.y1 *= 25;
    kek.z *= 25;
    kek.z1 *= 25;
    rot_x(&kek);
    rot_y(&kek);
    rot_z(&kek);
    line(kek.x,kek.y,kek.x1,kek.y1, m.mlx_win, m.mlx_ptr);
}

void    rot(t_kekmap kek)
{
    t_vector    m;
    int         y;
    int         x;

    y = 0;
    while (y < kek.mapy)
    {
        x = 0;
        while (x < kek.mapx)
        {
            if (x + 1 < kek.mapx)
            {
                m.x = kek.map[y][x].x;
                m.x1 = kek.map[y][x + 1].x;
                m.y = kek.map[y][x].y;
                m.y1 = kek.map[y][x + 1].y;
                m.z = kek.map[y][x + 1].z;
                m.z1 = kek.map[y][x + 1].z;
                ft_printf("x = %d, y = %d\n", x, y);
                scale(m, kek);
            }
                
            if (y + 1 < kek.mapy)
            {
                m.x = kek.map[y][x].x;
                m.x1 = kek.map[y + 1][x].x;
                m.y = kek.map[y][x].y;
                m.y1 = kek.map[y + 1][x].y;
                m.z = kek.map[y][x].z;
                m.z1 = kek.map[y + 1][x].z;
                scale(m, kek);
            }
            x++;
        }
        y++;
    }
}

void    ft_kek(t_kekmap kek)
{
    int     mlx_l;
    
    kek.mlx_ptr = mlx_init();
    kek.mlx_win = mlx_new_window(kek.mlx_ptr, 1000, 1000, "fdf");
    int y;
    int x;

    y = 0;
    while (y < kek.mapy)
    {
        x = 0;
        while (x < kek.mapx)
        {
            kek.map[y][x].x = x;
            kek.map[y][x].y = y;
            x++;
        }
        y++;
    }
    rot(kek);
    //kek.map[0][0].x = 500 - kek.mapx * 25 / 2;
    //kek.map[0][0].y = 500 - kek.mapy * 25 / 2;
    /*y = 0;
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
    }*/
    //draw_line(kek);
    //mlx_hook(kek.mlx_win, 2, 3, key_hook, &kek);
    mlx_l = mlx_loop(kek.mlx_ptr);
}