/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:36:35 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/16 23:22:52 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int         check_line(char *line, int i)
{
    if ((ft_isdigit(line[i]) == 0 && line[i] != ' ' && line[i] != '-') ||
    (line[i] == '-' && ft_isdigit(line[i + 1]) != 1))
        return (0);
    else
        return (1);
}

int         valid_map(char *str, int aux)
{
    int     i;
    int     fd;
    char    *line;
    int     col;

    fd = open(str, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        i = -1;
        col = 1;
        while (line[++i])
        {
            if (line == NULL || check_line(line, i) == 0)
                return (0);
            if (line[i] == ' ' &&
            (ft_isdigit(line[i + 1]) == 1 || line[i + 1] == '-'))
                col++;
        }
        if (aux == 0)
            aux = col;
        if (col != aux)
            return (0);
    }
    free(line);
    return (1);
}

t_kekmap       array(t_kekmap kek, int col, int ln, int fd, char *s)
{
    char    **str;
    char    *line;

    str = NULL;
    kek.map = (t_kek **)malloc(ln * sizeof(t_kek *));
    kek.mapx = -1;
    while (++kek.mapx < col)
        kek.map[kek.mapx] = (t_kek *)malloc(col * sizeof(t_kek));
    fd = open(s, O_RDONLY);
    kek.mapy = 0;
    while (get_next_line(fd, &line))
    {
        str = ft_strsplit(line, ' ');
        kek.mapx = -1;
        while (str[++kek.mapx])
            kek.map[kek.mapy][kek.mapx].z = ft_atoi(str[kek.mapx]);
        kek.mapy++;
        free(*str);
    }
    free(line);
    return (kek);
}

t_kekmap       maloc_array(t_kekmap kek, char *str)
{
    int     fd;
    int     col;
    int     ln;
    char    *line;
    int     i;

    fd = open(str, O_RDONLY);
    ln = 0;
    while (get_next_line(fd, &line))
    {
        i = -1;
        col = 1;
        while (line[++i])
        {
            if (line[i] == ' ' &&
            (ft_isdigit(line[i + 1]) == 1 || line[i + 1] == '-'))
                col++;
        }
        ln++;
    }
    kek = array(kek, col, ln, fd, str);
    free(line);
    return (kek);
}

int         main(int n, char **t)
{
    t_kekmap    kek;
    int         aux;

    kek.mapx = 0;
    kek.mapy = 0;
    kek.map = NULL;
    if (n != 2)
    {
        if (n == 1)
            ft_printf("No files");
        else
            ft_printf("More then 1 file");
        return (0);
    }
    aux = 0;
    if (valid_map(t[1], aux) == 0)
    {
        ft_printf("Invalid map\n");
        return (0);
    }
    kek = maloc_array(kek, t[1]);
    ft_kek(kek);
    return (0);
}