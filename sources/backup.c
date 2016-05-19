/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:09:02 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/19 16:06:18 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	fractal_julia(t_var *v)
{
	(void)v;
}

void	fractal_mandelbrot(t_var *v, long double mod)
{
	/*long double zoom_x = 500 / 2.4(0.6 - -2.1);	
	long double zoom_y = 500 / 2.4(1.2 - -1.2);
	long double cr;
	long double ci;
	long double zr;
	long double zi;
	long double tmp;
	int i;

	cr = -2.1 + (v->x / zoom_x + -2.1);
	ci = -2.1 + (v->y / zoom_y + -1.2);
	zr = 0.0;
	zi = 0.0;
	i = 0;
	while ((zr * zr + zi * zi) < 4.0 && i < 50)
	{
		tmp = zr;
		zr = zr *zr - zi* zi + cr;
		zi = -2 * zi * tmp + ci;
		i++;
	}*/
	int			i;

	i = -1;
	v->zr = 0.0;
	v->zi = 0.0;
	v->cr = MIN_X + ((long double)v->x * (MAX_X - MIN_X) / WIN_W);
	v->ci = MIN_Y + ((long double)v->y * (MAX_Y - MIN_Y) / WIN_H);
	while (++i < v->i && (v->zr * v->zr + f->zi * f->zi) < 4)
	{
		v->tmp = v->zr;
		v->zr = (v->zr * f->zr) - (v->xi * v->zi) + v->cr;
		v->zi = mod * v->zi * v->tmp + v->ci;
	}
	if (i == 50)
		put_pixel(v, 0xffffff, 0);
}

void	fractal_troisieme(t_var *v)
{
	(void)v;
}
