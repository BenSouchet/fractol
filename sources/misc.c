/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:09:02 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/20 16:12:34 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	fractal_julia(t_var *v)
{
	(void)v;
}

void	fractal_mandelbrot(t_var *v)
{
	v->i = -1.0;
	v->zr = 0.0;
	v->zi = 0.0;
	v->cr = (double)v->x / (WIN_H / (MAX_X - MIN_X)) + MIN_X;
	v->ci = (double)v->y / (WIN_H / (MAX_Y - MIN_Y)) + MIN_Y;
	while (++v->i < v->imax && (v->zr * v->zr + v->zi * v->zi) < 4)
	{
		v->tmp = v->zr;
		v->zr = (v->zr * v->zr) - (v->zi * v->zi) + v->cr;
		v->zi = v->mod * v->zi * v->tmp + v->ci;
	}
    v->color = ft_gradient_color(v->color1, v->color2, (v->i / v->imax));
    //rotation_fractal(v);
	put_pixel(v, 0);
}

void	fractal_troisieme(t_var *v)
{
	(void)v;
}
