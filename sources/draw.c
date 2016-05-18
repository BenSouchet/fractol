/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/17 17:23:57 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		put_pixel(t_var *v, int color, int type)
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
		rgb = (char*)&color;
		v->d[i] = rgb[0];
		v->d[++i] = rgb[1];
		v->d[++i] = rgb[2];
	}
	return (0);
}

void    user_interface(t_var *v)
{
	v->y = -1;
	while (++v->y < WIN_H && (v->x = 0) > -1)
		while (v->x <= 213 && put_pixel(v, BG_COLOR, 0) == 0)
			v->x++;
	v->nam = ft_strjoin("Fractal : ", ft_firstupper(v->ftl[v->num - 1]));
	v->len = WIN_W - 50 - ft_strlen(v->nam) * 10;
	v->x = 25;
	v->y = 25;
	mlx_draw(v, 188, 173);
	v->y = 197;
	mlx_draw(v, 188, 306);
	v->y = 331;
	mlx_draw(v, 188, 439);
	v->y = (WIN_H - 65);
	v->x = v->len - 1;
	mlx_draw(v, (WIN_W - 25), (WIN_H - 25));
}

void	user_interface_texts(t_var *v)
{
	mlx_string_put(v->mlx, v->win, 41, 35, UI_COLOR, "Controls Keys");
	mlx_string_put(v->mlx, v->win, 37, 63, UI_COLOR, "Colr = C");
	mlx_string_put(v->mlx, v->win, 37, 83, UI_COLOR, "Iter = W and S");
	mlx_string_put(v->mlx, v->win, 37, 103, UI_COLOR, "Zoom = + and -");
	mlx_string_put(v->mlx, v->win, 37, 123, UI_COLOR, "Presets = < >");
	mlx_string_put(v->mlx, v->win, 37, 143, UI_COLOR, "Reset = CLEAR");
	mlx_string_put(v->mlx, v->win, 37, 208, UI_COLOR, "Controls Mouse");
	mlx_string_put(v->mlx, v->win, 37, 236, UI_COLOR, "Julia = MOVE");
	mlx_string_put(v->mlx, v->win, 37, 256, UI_COLOR, "Zoom = SCROLL");
	mlx_string_put(v->mlx, v->win, 37, 276, UI_COLOR, "or LMB and RMB");
	mlx_string_put(v->mlx, v->win, 37, 341, UI_COLOR, "Fract Explorer");
	if (v->num == 1)
		mlx_string_put(v->mlx, v->win, 37, 369, UI_COLOR, "Julia = 1");
	else
		mlx_string_put(v->mlx, v->win, 37, 369, UI2_COLOR, "Julia = 1");
	if (v->num == 2)
		mlx_string_put(v->mlx, v->win, 37, 389, UI_COLOR, "Mandelbrot = 2");
	else
		mlx_string_put(v->mlx, v->win, 37, 389, UI2_COLOR, "Mandelbrot = 2");
	if (v->num == 3)
		mlx_string_put(v->mlx, v->win, 37, 409, UI_COLOR, "Toisieme = 3");
	else
		mlx_string_put(v->mlx, v->win, 37, 409, UI2_COLOR, "Toisieme = 3");
	mlx_string_put(v->mlx, v->win, v->len + 11, (WIN_H - 55), UI_COLOR, v->nam);
	free(v->nam);
}

void	mlx_draw(t_var *v, int x, int y)
{
	int tmp1;
	int tmp2;

	tmp1 = v->x;
	tmp2 = v->y;
	while (v->x <= x && put_pixel(v, UI_COLOR, 0) == 0)
		v->x++;
	while (v->y <= y && put_pixel(v, UI_COLOR, 0) == 0)
		v->y++;
	while (v->x >= tmp1 && put_pixel(v, UI_COLOR, 0) == 0)
		v->x--;
	while (v->y >= tmp2 && put_pixel(v, UI_COLOR, 0) == 0)
		v->y--;
}
