/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:09:02 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/19 18:18:54 by bsouchet         ###   ########.fr       */
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
	int r;
	int g;
	int b;

	v->i = -1;
	v->zr = 0.0;
	v->zi = 0.0;
	//v->cr = MIN_X + ((double)v->x * (MAX_X - MIN_X) / WIN_W);
	v->cr = (double)v->x / (WIN_H/*(WIN_W - 213)*/ / (MAX_X - MIN_X)) + MIN_X;
	//v->ci = MIN_Y + ((double)v->y * (MAX_Y - MIN_Y) / WIN_H);
	v->ci = (double)v->y / (WIN_H / (MAX_Y - MIN_Y)) + MIN_Y;
	while (++v->i < v->imax && (v->zr * v->zr + v->zi * v->zi) < 4)
	{
		v->tmp = v->zr;
		v->zr = (v->zr * v->zr) - (v->zi * v->zi) + v->cr;
		v->zi = mod * v->zi * v->tmp + v->ci;
	}
	r = 255.0 * (1.0 - ((double)v->i/(double)v->imax));
	g = 255.0 * (1.0 - ((double)v->i/(double)v->imax));
	b = 255.0 * (1.0 - ((double)v->i/(double)v->imax));
	//printf("r: %f --- g: %f --- b: %f\n", r, g, b);
	int color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	//if (v->i == 50)
		put_pixel(v, color, 0);
}

void	fractal_troisieme(t_var *v)
{
	(void)v;
}
