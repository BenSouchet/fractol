#include "fractol.h"

void    draw_line(t_var *v, t_point *p1, t_point *p2)
{
    double  tx;
    double  dist_x;
    double  dist_y;

    tx = 0.0;
    dist_x = v->tab[v->p][y][x + 1][0] - v->tab[v->p][y][x][0];
    dist_y = v->tab[v->p][y][x + 1][1] - v->tab[v->p][y][x][1];
    while (tx <= 1)
    {
        v->x = v->tab[v->p][y][x][0] + (dist_x * tx) + v->mov[v->p][0];
        v->y = v->tab[v->p][y][x][1] + (dist_y * tx) + v->mov[v->p][1];
        put_pixel(v, face_color(v), 0);
        tx += 1. / sqrt((dist_x * dist_x) + (dist_y * dist_y));
    }
}

void         omg_bro(int num_points, int diameter)
{
    double spacing;

    spacing = (num_points < 360) ? 360.0 / (double)num_points : 360;
    printf("degrees : %f\n");
}
