/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:09:02 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/07 19:25:43 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			rotate_fractal(t_var *v, int rot)
{
	if (rot >= 0)
		while (rot >= 360)
			rot -= 360;
	else
		while (rot < -0)
			rot += 360;
	if (rot == 0 && (v->e = 0) == 0)
		while (v->z < 0)
			v->z = v->z * -1;
	else if (rot == 90 && (v->e = 1) == 1)
		while (v->z < 0)
			v->z = v->z * -1;
	else if (rot == 180 && (v->e = 2) == 2)
		while (v->z > 0)
			v->z = v->z * -1;
	else if (rot == 270 && (v->e = 3) == 3)
		while (v->z > 0)
			v->z = v->z * -1;
	v->minx = ((MID_W + v->padx) / (v->z / 2)) / -2;
	v->miny = ((MID_H + v->pady) / (v->z / 2)) / -2;
}

int				edit_hue_hex(t_var *v)
{
	t_hsv	hsv;
	t_rgb	rgb;

	if (v->i == v->imax)
		return (0x000000);
	else
	{
		hsv.h = v->clr_h + ((240. / v->imax) * v->i);
		hsv.s = v->clr_s;
		hsv.v = v->clr_v - (((v->clr_v - 0.10) / 100.0) * v->i);
		while (hsv.h < 0.)
			hsv.h += 360.0;
		while (hsv.h > 360.)
			hsv.h -= 360.0;
		rgb = ft_hsv_to_rgb(hsv);
	}
	return (ft_rgb_to_hex(rgb));
}

void			fractal_julia(t_var *v)
{
	v->i = -1.0;
	v->mod = 2;
	v->zr = (v->e == 0 || v->e == 2) ? (D(v->x) / v->z) + v->minx :
	(D(v->y) / v->z) + v->miny;
	v->zi = (v->e == 0 || v->e == 2) ? (D(v->y) / v->z) + v->miny :
	(D(v->x) / v->z) + v->minx;
	while (++v->i < v->imax && (v->zr * v->zr + v->zi * v->zi) < 4)
	{
		v->tmp = v->zr;
		v->zr = (v->zr * v->zr) - (v->zi * v->zi) + v->jr;
		v->zi = v->mod * v->zi * v->tmp + v->ji;
	}
	v->clr = edit_hue_hex(v);
	if (((v->x >= 25 && v->x <= 188) &&
	((v->y >= 25 && v->y <= 213) || (v->y >= 237 && v->y <= 326) ||
	(v->y >= (WIN_H - 133) && v->y <= (WIN_H - 25)))) ||
	(v->x >= (v->len - 1) && v->x <= (WIN_W - 25) &&
	v->y >= (WIN_H - 65) && v->y <= (WIN_H - 25)))
		v->clr = ft_shade_color(v->clr, 0.35);
	put_pixel(v, 0);
}

void			fractal_mandelbrot(t_var *v)
{
	v->i = -2.0;
	v->zr = 0.0;
	v->zi = 0.0;
	v->mod = (v->num == 2) ? 2 : -2;
	v->mr = (v->e == 0 || v->e == 2) ? (D(v->x) / v->z) + v->minx :
	(D(v->y) / v->z) + v->miny;
	v->mi = (v->e == 0 || v->e == 2) ? (D(v->y) / v->z) + v->miny :
	(D(v->x) / v->z) + v->minx;
	while (++v->i < v->imax && (v->zr * v->zr + v->zi * v->zi) < 4)
	{
		v->tmp = v->zr;
		v->zr = (v->zr * v->zr) - (v->zi * v->zi) + v->mr;
		v->zi = v->mod * v->zi * v->tmp + v->mi;
	}
	v->clr = edit_hue_hex(v);
	if (((v->x >= 25 && v->x <= 188) &&
	((v->y >= 25 && v->y <= 213) || (v->y >= 237 && v->y <= 326) ||
	(v->y >= (WIN_H - 133) && v->y <= (WIN_H - 25)))) ||
	(v->x >= (v->len - 1) && v->x <= (WIN_W - 25) &&
	v->y >= (WIN_H - 65) && v->y <= (WIN_H - 25)))
		v->clr = ft_shade_color(v->clr, 0.35);
	put_pixel(v, 0);
}
