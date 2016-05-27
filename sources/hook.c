/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:35:58 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/27 14:03:20 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int		expose_hook(t_var *v)
{
	v->minx = (((WIN_W + v->padx) / 2) / (v->zoom / 2)) / -2;
	v->miny = (((WIN_H + v->pady) / 2) / (v->zoom / 2)) / -2;
	v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	draw_fractal(v);
    user_interface(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	user_interface_texts(v);
	return (0);
}

int		key_hook(int keycode, t_var *v)
{
    int r;

    r = 0;
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else
	{
		if (keycode == 83 && v->num != 1 && ++r > 0)
			v->num = 1;
		else if (keycode == 84 && v->num != 2 && ++r > 0)
			v->num = 2;
		else if (keycode == 85 && v->num != 3 && ++r > 0)
		{
			v->mod = -2;
			v->num = 3;
		}
		else if ((keycode == 1 || keycode == 46) && v->m == UI_CLR && ++r > 0)
			v->m = UI_DCLR;
		else if ((keycode == 1 || keycode == 46) && v->m != UI_CLR && ++r > 0)
			v->m = UI_CLR;
		else if (keycode == 123 && ++r > 0)
			v->padx -= 20.0;
		else if (keycode == 124 && ++r > 0)
			v->padx += 20.0;
        else if (keycode == 126 && ++r > 0)
            v->pady -= 20.0;
        else if (keycode == 125 && ++r > 0)
            v->pady += 20.0;
        else if (keycode == 69 && (v->edit == 0 || v->edit == 1) && ++r > 0)
            v->zoom += 10.0;
		else if (keycode == 69 && (v->edit == 2 || v->edit == 3) && ++r > 0)
			v->zoom -= 10.0;
        else if (keycode == 78 && (v->edit == 0 || v->edit == 1) && v->zoom > 10 && ++r > 0)
			v->zoom -= 10.0;
		else if (keycode == 78 && (v->edit == 2 || v->edit == 3) && v->zoom < -10 && ++r > 0)
			v->zoom += 10.0;
		else if (keycode == 12 && ++r > 0)
			v->imax += 2.0;
		else if (keycode == 13 && v->imax > 2 && ++r > 0)
			v->imax -= 2.0;
		else if (keycode == 15 && ++r > 0)
			v->rot -= 90;
		else if (keycode == 17 && ++r > 0)
			v->rot += 90;
		else if (keycode == 71 && ++r > 0)
		{
			v->rot = 0;
			v->edit = 0;
			v->mod = 2.0;
			v->padx = 0.0;
			v->pady = 0.0;
			v->m = UI_DCLR;
			v->zoom = 170.0;
		}
        if (r > 0)
        {
		    mlx_destroy_image(v->mlx, v->img);
		    mlx_clear_window(v->mlx, v->win);
		    expose_hook(v);
        }
	}
	return (0);
}

int		close_hook(int button, t_var *v)
{
	(void)button;
	(void)v;
	exit(0);
	return (0);
}
