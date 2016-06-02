/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/27 13:55:25 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		put_pixel(t_var *v, int type)
{
	int		i;
	int		x;
	int		y;
	char	*rgb;

	x = v->x;
	y = v->y;
	if (((type == 1 && x > 213) || (type != 1 && x >= 0))
			&& x < WIN_W && y >= 0 && y < WIN_H)
	{
		i = ((int)v->x * (v->bpp / 8)) + ((int)v->y * v->sl);
		rgb = (char*)&v->color;
		v->d[i] = rgb[0];
		v->d[++i] = rgb[1];
		v->d[++i] = rgb[2];
	}
	return (0);
}

void	draw_fractal(t_var *v)
{
	v->y = -1;
    v->nam = ft_strjoin("Fractal : ", ft_firstupper(v->ftl[v->num - 1]));
    v->len = WIN_W - 50 - ft_strlen(v->nam) * 10;
    rotate_fractal(v, v->rot);
	while (++v->y < WIN_H && (v->x = -1) == -1)
	{
		while (++v->x < WIN_W)
		{
			if (v->num == 1)
				fractal_julia(v);
			else if (v->num == 2)
				fractal_mandelbrot(v);
			else if (v->num == 3)
				fractal_mandelbrot(v);
		}
	}
}

void    user_interface(t_var *v)
{
	v->x = 25;
	v->y = 25;
	mlx_draw(v, 188, 213, UI_CLR);
	v->y = 237;
	mlx_draw(v, 188, 326, v->m);
	v->y = WIN_H - 133;
	mlx_draw(v, 188, (WIN_H - 25), UI_CLR);
	v->y = (WIN_H - 65);
	v->x = v->len - 1;
	mlx_draw(v, (WIN_W - 25), (WIN_H - 25), UI_CLR);
}

void	user_interface_texts(t_var *v)
{
	mlx_string_put(v->mlx, v->win, 41, 35, UI_CLR, "Controls Keys");
	mlx_string_put(v->mlx, v->win, 37, 63, UI_CLR, "Move = ^ v < >");
	mlx_string_put(v->mlx, v->win, 37, 83, UI_CLR, "Iter = W and Q");
	mlx_string_put(v->mlx, v->win, 37, 103, UI_CLR, "Zoom = + and -");
	mlx_string_put(v->mlx, v->win, 37, 123, UI_CLR, "Rot8 = R and T");
	mlx_string_put(v->mlx, v->win, 37, 143, UI_CLR, "Mouse = M or S");
	mlx_string_put(v->mlx, v->win, 37, 163, UI_CLR, "Color = SHIFT");
	mlx_string_put(v->mlx, v->win, 37, 183, UI_CLR, "Reset = CLEAR");
	mlx_string_put(v->mlx, v->win, 37, 248, v->m, "Controls Mouse");
	mlx_string_put(v->mlx, v->win, 37, 276, v->m, "Zoom = SCROLL");
	mlx_string_put(v->mlx, v->win, 37, 296, v->m, "or LMB and RMB");
	mlx_string_put(v->mlx, v->win, 37, (WIN_H - 123), UI_CLR, "Fract Explorer");
	mlx_string_put(v->mlx, v->win, 37, (WIN_H - 95), UI_CLR, "1 = Julia");
	mlx_string_put(v->mlx, v->win, 37, (WIN_H - 75), UI_CLR, "2 = Mandelbrot");
	mlx_string_put(v->mlx, v->win, 37, (WIN_H - 55), UI_CLR, "3 = Tricorn");
	mlx_string_put(v->mlx, v->win, v->len + 11, (WIN_H - 55), UI_CLR, v->nam);
	free(v->nam);
}

void	mlx_draw(t_var *v, int x, int y, int clr)
{
	int tmp1;
	int tmp2;

	tmp1 = v->x;
	tmp2 = v->y;
	v->color = ft_darken_color(clr, 0.20);
	while (v->x <= x && put_pixel(v, 0) == 0)
		v->x++;
	while (v->y <= y && put_pixel(v, 0) == 0)
		v->y++;
	while (v->x > tmp1 && put_pixel(v, 0) == 0)
		v->x--;
	while (v->y > tmp2 && put_pixel(v, 0) == 0)
		v->y--;
}
